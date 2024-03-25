#include "includes.h"
#include "SDK.hpp"
#include <vector>
#include <string>
#include <thread>
#include "globals.h"
#include "vector.h"
#include "functions.h"
#include "GUI.h"
#include "kiero/minhook/include/MinHook.h"

using namespace SDK;
using std::cout;

bool debug = false;
bool alive = true;
bool first = true;
bool showmenu = true;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
FILE* Dummy{};

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

	SetColorsFlags();
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 24.0f);

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
	draw_list = ImGui::GetBackgroundDrawList();
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	switch (uMsg) {
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_INSERT:
			showmenu = !showmenu;
			break;
		}
	}

	if (showmenu) return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (showmenu)
	{
		Draw_GUI();
	}

	PlayerArray = World->GameState->PlayerArray;

	float MaxDistance = FLT_MAX;
	SDK::AActor* closest_actor{};
	SDK::FRotator closest_actor_rotation{};
	float MaxDistanceTP = FLT_MAX;

	for (int i = 0; i < PlayerArray.Num(); i++)
	{
		if (PlayerArray.Num() <= 5) continue;

		ent = PlayerArray[i];

		MyController = World->OwningGameInstance->LocalPlayers[0]->PlayerController;

		if (!ent) continue;
		if (!ent->PawnPrivate) continue;

		if (!MyController) continue;
		if (!MyController->PlayerCameraManager) continue;
		if (!MyController->AcknowledgedPawn) continue;

		if (ent == MyController->PlayerState) continue;

		MyPawn = MyController->AcknowledgedPawn;
		CharacterClass = static_cast<AHDPlayerCharacter*>(MyPawn);

		auto ActorCharacterClass = static_cast<AHDPlayerCharacter*>(ent->PawnPrivate);

		if (!ActorCharacterClass->Mesh) continue;

		auto mesh = ActorCharacterClass->Mesh;

		auto LocalPos = CharacterClass->ReplicatedMovement.Location;

		auto Weapon = reinterpret_cast<AHDBaseWeapon*>(CharacterClass->EquippedItem);
		auto EnemieWeapon = reinterpret_cast<AHDBaseWeapon*>(ActorCharacterClass->EquippedItem);
		auto LocalTeam = CharacterClass->TeamNum;
		auto Team = ActorCharacterClass->TeamNum;

		if (globals::TeamCheck)
		{
			if (LocalTeam == Team) continue;
		}

		auto Health = ActorCharacterClass->Health;

		if (Health <= 0) continue;

		if (globals::rainbow)
		{
			StartRainbowColor();
		}

		SDK::FVector location{};
		SDK::FVector BoxExtent{};
		ActorCharacterClass->GetActorBounds(true, &location, &BoxExtent, false);

		float ActorDistance = LocalPos.GetDistanceToInMeters(location);
		std::string ActorDistanceString = ("[" + std::to_string(static_cast<int>(ActorDistance)) + " M]");

		if (globals::superSpeed)
		{
			CharacterClass->CharacterMovement->MaxWalkSpeed = globals::Speed_force;
			CharacterClass->CharacterMovement->MaxAcceleration = globals::Speed_force;
		}
		if (globals::Fly)
		{
			CharacterClass->CharacterMovement->MaxFlySpeed = 20000.f;
			CharacterClass->CharacterMovement->MovementMode = SDK::EMovementMode::MOVE_Flying;
			if (GetAsyncKeyState(VK_SPACE))
			{
				SDK::FVector posUP = { 0.f, 0.f, 10.f };
				CharacterClass->CharacterMovement->AddInputVector(posUP, true);
			}
			if (GetAsyncKeyState(VK_LCONTROL))
			{
				SDK::FVector posDOWN = { 0.f, 0.f, -10.f };
				CharacterClass->CharacterMovement->AddInputVector(posDOWN, true);
			}
		}
		else
		{
			if (CharacterClass->CharacterMovement->MovementMode == SDK::EMovementMode::MOVE_Flying)
				CharacterClass->CharacterMovement->MovementMode = SDK::EMovementMode::MOVE_Falling;
		}

		if (globals::GodMode)
		{
			CharacterClass->MaxHealth = 999.f;
			CharacterClass->Health = 999.f;
		}
		if (globals::InfiniteAmmo)
			Weapon->bUsesAmmo = false;
		else
			Weapon->bUsesAmmo = true;

		if (globals::InstaFireRate)
		{
			Weapon->FireRate = globals::FireRate;
		}
		if (globals::NoRecoil)
		{
			Weapon->bNoRecoil = true;
		}
		if (globals::BulletsPerShoot_bool)
			Weapon->ShotsPerBurst = globals::BulletsPerShoot;

		auto CameraLocation = MyController->PlayerCameraManager->GetCameraLocation();
		auto CameraRotation = MyController->PlayerCameraManager->GetCameraRotation();


		FVector2D Top{};
		FVector2D Bottom{};
		FVector2D locationw2s{};

		SDK::FVector head_bone_pos = mesh->GetSocketLocation(mesh->GetBoneName(48));

		AimbotBone = head_bone_pos;

		SDK::FVector feet_bone_pos = mesh->GetSocketLocation(mesh->GetBoneName(59));

		FVector feet_middle_pos = { location.X, location.Y, feet_bone_pos.Z };

		if (globals::PlayerTp)
		{
			if (LocalPos.GetDistanceTo(location) <= MaxDistanceTP)
			{
				MaxDistanceTP = LocalPos.GetDistanceTo(location);
				closest_actor_TP = location;
			}
		}

		if (globals::ESP_FeetCircle3D)
		{
			circlePoints_Feet = generateCirclePoints(feet_middle_pos, 100.f, MyController);
		}
		if (globals::ESP_Pill3D)
		{
			circlePoints_Head = generateCirclePoints(head_bone_pos, 100.f, MyController);
		}

		if (MyController->LineOfSightTo(ActorCharacterClass, MyController->PlayerCameraManager->CameraCachePrivate.POV.Location, false))
			isVIsible = true;
		else isVIsible = false;
			

		if (globals::Chams && ChamsMat)
		{
			ApplyChams(mesh, ChamsMat, globals::ChamsColor, true, true, isVIsible);
		}

		if (globals::WeaponChams && WeaponChamsMat && Weapon)
		{
			if (!Weapon->GetWeaponMesh1P()) continue;

			ApplyChams(Weapon->GetWeaponMesh1P(), WeaponChamsMat, globals::ChamsWeaponColor, true, false, isVIsible);
		}

		if (globals::EnemieWeaponChams && EnemieWEaponMat && EnemieWeapon)
		{
			if (!EnemieWeapon->GetWeaponMesh1P()) continue;

			ApplyChams(EnemieWeapon->GetWeaponMesh1P(), EnemieWEaponMat, globals::EnemieWeaponChamsColor, false, false, isVIsible);
		}
		if (globals::ShowFPS)
		{
			std::string fps = std::to_string(static_cast<int>(ImGui::GetIO().Framerate));
			ImGui::GetBackgroundDrawList()->AddText(ImVec2(1920 - ImGui::CalcTextSize(fps.c_str()).x, 0), ImColor(0.f, 255.f, 0.f), fps.c_str());
		}
		if (globals::ShowMouse && showmenu)
		{
			auto MousePos = ImGui::GetMousePos();
			ImGui::GetForegroundDrawList()->AddCircleFilled(MousePos, 4.f, ImColor{ 1.f, 1.f, 1.f });
		}
		if (globals::Croshhair)
			ESP::DrawCrosshair(globals::CroshhairSize, globals::CroshhairColor, globals::CroshhairWidth, true, false);

		if (MyController->ProjectWorldLocationToScreen(feet_middle_pos, &Bottom, false) && MyController->ProjectWorldLocationToScreen(head_bone_pos, &Top, false))
		{
			const float h = Bottom.Y - Top.Y;
			const float w = h * 0.3f;

			if (globals::ESP_Distance_bool)
			{
				if (LocalPos.GetDistanceTo(location) >= globals::ESP_Distance) continue;
			}

			if (globals::ESP_Skeleton)
			{
				DrawBones(mesh, MyController, GUI_Colors::Visible, true, true);
			}
			if (globals::ESP_Box)
			{
				ESP::DrawBox({ Top.X - w, Top.Y }, { Bottom.X + w, Bottom.Y }, GUI_Colors::Visible, 0.f, true, true);
				ESP::DrawBox({ Top.X - w - 1, Top.Y - 1 }, { Bottom.X + w + 1, Bottom.Y + 1 }, Colors::Black, 0.f, false, false);
				ESP::DrawBox({ Top.X - w + 1, Top.Y + 1 }, { Bottom.X + w - 1, Bottom.Y - 1 }, Colors::Black, 0.f, false, false);
			}
			if (globals::ESP_BoxCornered)
			{
				ESP::DrawCornerBox(Top.X - w + 1, Top.Y + 1, w * 1.8f - 2, h - 2, 1, Colors::Black, false, false); //IN
				ESP::DrawCornerBox(Top.X - w - 1, Top.Y - 1, w * 1.8f + 2, h + 2, 1, Colors::Black, false, false); //OUT
				ESP::DrawCornerBox(Top.X - w, Top.Y, w * 1.8f, h, 1, GUI_Colors::Visible, true, true); //middle
			}
			if (globals::ESP_Names)
			{
				ESP::DrawText2({ Top.X - w, Top.Y - 15 }, GUI_Colors::Visible, ent->PawnPrivate->GetName().c_str(), false, false);

			}
			if (globals::ESP_Snaplines)
			{
				ESP::DrawLine({ 1920 / 2, 0 }, Top, GUI_Colors::Visible, 1.f, true, true);
			}

			if (globals::ESP_FeetCircle3D)
			{
				DrawCircle3D(circlePoints_Feet, Colors::White, false, false);
			}
			if (globals::ESP_Pill3D)
			{
				DrawPill3D(circlePoints_Feet, circlePoints_Head, Colors::White, true, false);
			}
			if (globals::ESP_3DBox)
			{
				ESP::Draw3DBox(location, BoxExtent, MyController, GUI_Colors::Visible, true, true);
			}
			if (globals::DrawFov)
			{
				ESP::DrawCircle({ 1920 / 2, 1080 / 2 }, globals::aimbot_FOV, Colors::White, 50, 1.f, true, false);
			}
			if (globals::ESP_HealthBar)
			{
				ESP::DrawFilledBox({ Top.X - w - 6, Top.Y }, { Top.X - w - 3, Bottom.Y }, Colors::Black, 0.f, false, false);
				ESP::DrawFilledBox({ Top.X - w - 5, Bottom.Y - (h * (Health * 0.01f)) }, { Top.X - w - 4, Bottom.Y }, Colors::Green, 0.f, false, false);
			}
			if (globals::ESP_DistanceText)
			{
				ESP::DrawText2({ Bottom.X - w, Bottom.Y - h - 12 }, Colors::White, (ActorDistanceString).c_str(), true, false);
			}
			if (isVIsible && globals::ESP_VisibleLIne)
			{
				if (isVIsible)
					ESP::DrawLine({ 1920 / 2, 1080 / 2 }, { Top.X, Top.Y }, Colors::Green, 1.f, false, false);
			}

			if (globals::VisCheckAim)
			{
				if (!isVIsible) continue;
			}

			FVector2D w2s_head_bone_pos{};
			if (MyController->ProjectWorldLocationToScreen(head_bone_pos, &w2s_head_bone_pos, false))
			{
				auto rot = UKismetMathLibrary::FindLookAtRotation(CameraLocation, head_bone_pos);

				FVector2D screen_middle = { 1920 / 2, 1080 / 2 };

				aimbot_distance = UKismetMathLibrary::Distance2D(w2s_head_bone_pos, screen_middle);

				if (aimbot_distance < MaxDistance && aimbot_distance <= globals::aimbot_FOV)
				{
					MaxDistance = aimbot_distance;
					closest_actor = ent->PawnPrivate;
					closest_actor_rotation = rot;
					closest_actor_head = head_bone_pos;
					closest_actor_headw2s = w2s_head_bone_pos;
					if (isVIsible) closest_actor_visible = true;
					else closest_actor_visible = false;
				}
			}

		}
	}
	if (closest_actor && globals::aimbot && GetAsyncKeyState(VK_XBUTTON1))
	{
		MyController->SetControlRotation(closest_actor_rotation);

	}
	if (closest_actor && globals::ESP_AimLine)
	{
		ESP::DrawLine({ 1920 / 2, 1080 / 2 }, closest_actor_headw2s, GUI_Colors::Visible, 1.f, false, false);
	}
	if (closest_actor_TP.X != 0 && globals::PlayerTp && GetAsyncKeyState(VK_LMENU))
	{
		CharacterClass->K2_TeleportTo({ closest_actor_TP.X + 100.f, closest_actor_TP.Y, closest_actor_TP.Z + 100.f }, MyController->PlayerCameraManager->GetCameraRotation());
	}
			

	if (!alive)
	{
		kiero::shutdown();
		pDevice->Release();
		pContext->Release();
		pSwapChain->Release();
		oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)(oWndProc));
	}

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD MainThread(HMODULE hModule)
{
	if (debug)
	{
		AllocConsole();
		freopen_s(&Dummy, "CONOUT$", "w", stdout);
	}

	World = SDK::UWorld::GetWorld();
	Engine = SDK::UEngine::GetEngine();

	PlayerArray = World->GameState->PlayerArray;
	MyController = World->OwningGameInstance->LocalPlayers[0]->PlayerController;

	//TransparentMaterial = UObject::FindObject<UMaterial>("Material M_MasterGlass.M_MasterGlass");
	WireframeMaterial = UObject::FindObject<UMaterial>("Material WireframeMaterial.WireframeMaterial");
	FlameMaterial = UObject::FindObject<UMaterial>("Material M_FlameBig.M_FlameBig");

	if (WireframeMaterial)
	{
		WireframeMaterial->bDisableDepthTest = true;
		WireframeMaterial->Wireframe = true;
		WireframeMaterial->BlendMode = SDK::EBlendMode::BLEND_Additive;
		WireframeMaterial->MaterialDomain = SDK::EMaterialDomain::MD_Surface;
		WireframeMaterial->AllowTranslucentCustomDepthWrites = true;
		WireframeMaterial->bIsBlendable = true;
		WireframeMaterial->LightmassSettings.EmissiveBoost = 999;
		WireframeMaterial->LightmassSettings.DiffuseBoost = 0;
	}
	
	ChamsMat = SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(World, WireframeMaterial, StrToName(L"ChamsMaterial"));
	ChamsMatVisible = SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(World, WireframeMaterial, StrToName(L"ChamsVisibleMaterial"));
	ChamsMatNotVisible = SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(World, WireframeMaterial, StrToName(L"ChamsNotVisibleMaterial"));
	WeaponChamsMat = SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(World, WireframeMaterial, StrToName(L"WeaponMaterial"));
	EnemieWEaponMat = SDK::UKismetMaterialLibrary::CreateDynamicMaterialInstance(World, WireframeMaterial, StrToName(L"EnemieWeaponMaterial"));

	if (ChamsMat)
	{
		ChamsMat->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(globals::ChamsColor));
		WeaponChamsMat->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(globals::ChamsWeaponColor));
		EnemieWEaponMat->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(globals::EnemieWeaponChamsColor));
		ChamsMatVisible->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(GUI_Colors::Visible));
		ChamsMatNotVisible->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(GUI_Colors::NotVisible));
	}

	bool init_hook = false;
	if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
	{
		kiero::bind(8, (void**)&oPresent, hkPresent);
		init_hook = true;
	}

	while (alive)
	{
		if (GetAsyncKeyState(VK_END))
		{
			alive = false;
			Sleep(1000);
			if (debug)
			{
				FreeConsole();
				if (Dummy)
					fclose(Dummy);
			}
			FreeLibraryAndExitThread(hModule, 0);
		}
	}

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}