#include "SDK.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "globals.h"
#include "vector.h"
#include <array>

namespace ESP
{
	inline void DrawLine(SDK::FVector2D posA, SDK::FVector2D posB, float color[3], float t = 1.f, bool bRainbowMode = false, bool bVisibility = false, bool outline = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}

		if (outline)
			draw_list->AddLine(ImVec2(posA.X, posA.Y), ImVec2(posB.X, posB.Y), ImColor(0.f, 0.f, 0.f), t+1.f);
		draw_list->AddLine(ImVec2(posA.X, posA.Y), ImVec2(posB.X, posB.Y), ImColor(color[0], color[1], color[2]), t);
	}

	inline void DrawBox(SDK::FVector2D posA, SDK::FVector2D posB, float color[3], float rounding = 0.f, bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		draw_list->AddRect(ImVec2(posA.X, posA.Y), ImVec2(posB.X, posB.Y), ImColor(color[0], color[1], color[2]), rounding);
	}
	inline void DrawFilledRect(int x, int y, int w, int h, float color[3], bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color[0], color[1], color[2]));
	}

	inline void DrawCornerBox(int x, int y, int w, int h, int borderPx, float color[3], bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		ESP::DrawFilledRect(x + borderPx, y, w / 3, borderPx, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x + w - w / 3 + borderPx, y, w / 3, borderPx, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x, y, borderPx, h / 3, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x + borderPx, y + h + borderPx, w / 3, borderPx, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x + w - w / 3 + borderPx, y + h + borderPx, w / 3, borderPx, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x + w + borderPx, y, borderPx, h / 3, color, bRainbowMode, bVisibility);
		ESP::DrawFilledRect(x + w + borderPx, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color, bRainbowMode, bVisibility);
	}
	inline void DrawFilledBox(SDK::FVector2D posA, SDK::FVector2D posB, float color[3], float rounding = 0.f, bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		draw_list->AddRectFilled(ImVec2(posA.X, posA.Y), ImVec2(posB.X, posB.Y), ImColor(color[0], color[1], color[2]), rounding);
	}

	inline void DrawText2(SDK::FVector2D pos, float color[3], const char* text, bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		draw_list->AddText(ImVec2(pos.X, pos.Y), ImColor(color[0], color[1], color[2]), text);
	}

	inline void DrawCircle(SDK::FVector2D pos, float radius, float color[3], int num_segments = 12, float t = 1.f, bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		draw_list->AddCircle(ImVec2(pos.X, pos.Y), radius, ImColor(color[0], color[1], color[2]), num_segments, t);
	}
	inline void DrawCircleFilled(SDK::FVector2D pos, float radius, float color[3], int num_segments = 12, bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		draw_list->AddCircleFilled(ImVec2(pos.X, pos.Y), radius, ImColor(color[0], color[1], color[2]), num_segments);
	}
	inline void DrawCrosshair(const float aSize, float color[], float w, bool bRainbowMode = false, bool bVisibility = false) {
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			color = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				color = GUI_Colors::Visible;
			else
				color = GUI_Colors::NotVisible;
		}
		ImColor colour = ImColor(color[0], color[1], color[2]);
		draw_list->AddLine({ 1920 / 2,1080 / 2 - (aSize + 1) }, { 1920 / 2 ,1080 / 2 + (aSize + 1) }, colour, w);
		draw_list->AddLine({ 1920 / 2 - (aSize + 1),1080 / 2 }, { 1920 / 2 + (aSize + 1), 1080 / 2 }, colour, w);
	}
	inline void Draw3DBox(SDK::FVector& center, SDK::FVector& Bounds, SDK::APlayerController* Controller, float col[3], bool bRainbowMode = false, bool bVisibility = false)
	{
		if (globals::rainbow && globals::rainbowESP && bRainbowMode)
		{
			col = globals::rainbowColor;
		}
		else if (bVisibility)
		{
			if (isVIsible)
				col = GUI_Colors::Visible;
			else
				col = GUI_Colors::NotVisible;
		}
		const float wX = (center.X + Bounds.X) - (center.X - Bounds.X);
		const float wY = (center.Y + Bounds.Y) - (center.Y - Bounds.Y);

		SDK::FVector Top{ center.X, center.Y, center.Z + Bounds.Z };
		SDK::FVector Bottom{ center.X, center.Y, center.Z - Bounds.Z };

		SDK::FVector a1 = { center.X - wX / 2, center.Y + wY / 2, Bottom.Z };
		SDK::FVector a2 = { center.X + wX / 2, center.Y + wY / 2, Bottom.Z };
		SDK::FVector a3 = { center.X - wX / 2, center.Y - wY / 2, Bottom.Z };
		SDK::FVector a4 = { center.X + wX / 2, center.Y - wY / 2, Bottom.Z };

		SDK::FVector b1 = { center.X - wX / 2, center.Y + wY / 2, Top.Z };
		SDK::FVector b2 = { center.X + wX / 2, center.Y + wY / 2, Top.Z };
		SDK::FVector b3 = { center.X - wX / 2, center.Y - wY / 2, Top.Z };
		SDK::FVector b4 = { center.X + wX / 2, center.Y - wY / 2, Top.Z };

		SDK::FVector2D a1w2s{};
		SDK::FVector2D a2w2s{};
		SDK::FVector2D a3w2s{};
		SDK::FVector2D a4w2s{};

		SDK::FVector2D b1w2s{};
		SDK::FVector2D b2w2s{};
		SDK::FVector2D b3w2s{};
		SDK::FVector2D b4w2s{};

		if (Controller->ProjectWorldLocationToScreen(a1, &a1w2s, false) && Controller->ProjectWorldLocationToScreen(a2, &a2w2s, false)
			&& Controller->ProjectWorldLocationToScreen(a3, &a3w2s, false) && Controller->ProjectWorldLocationToScreen(a4, &a4w2s, false)
			&& Controller->ProjectWorldLocationToScreen(b1, &b1w2s, false) && Controller->ProjectWorldLocationToScreen(b2, &b2w2s, false)
			&& Controller->ProjectWorldLocationToScreen(b3, &b3w2s, false) && Controller->ProjectWorldLocationToScreen(b4, &b4w2s, false))
		{
			ESP::DrawLine(a1w2s, a2w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(a2w2s, a4w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(a4w2s, a3w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(a3w2s, a1w2s, col, 1.f, bRainbowMode, bVisibility);

			ESP::DrawLine(b1w2s, b2w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(b2w2s, b4w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(b4w2s, b3w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(b3w2s, b1w2s, col, 1.f, bRainbowMode, bVisibility);

			ESP::DrawLine(a1w2s, b1w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(a2w2s, b2w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(a3w2s, b3w2s, col, 1.f, bRainbowMode, bVisibility);
			ESP::DrawLine(a4w2s, b4w2s, col, 1.f, bRainbowMode, bVisibility);
		}
	}
}

struct Bone {
    int start;
    int end;
};

inline constexpr Bone makeBone(int start, int end) {
    return { start, end };
}

inline constexpr std::array<Bone, 58> bones_map{
    makeBone(48, 47),
    makeBone(47, 26),
    makeBone(47, 5),
    makeBone(26, 27), 
    makeBone(27, 28), 
    makeBone(28, 45), 
    makeBone(45, 29), 
    makeBone(29, 42), 
    makeBone(42, 43), 
    makeBone(43, 44), 
    makeBone(29, 33), 
    makeBone(29, 31),
    makeBone(31, 32), 
    makeBone(33, 34), 
    makeBone(34, 35), 
    makeBone(29, 39), 
    makeBone(39, 40), 
    makeBone(40, 41), 
    makeBone(29, 36),
    makeBone(36, 37), 
    makeBone(37, 38), 
    makeBone(26, 5), 
    makeBone(5, 25),  
    makeBone(25, 7),  
    makeBone(7, 24), 
    makeBone(24, 8),  
    makeBone(8, 21), 
    makeBone(21, 22), 
    makeBone(22, 23), 
    makeBone(8, 9), 
    makeBone(9, 10), 
    makeBone(10, 11), 
    makeBone(8, 12), 
    makeBone(12, 13), 
    makeBone(13, 14), 
    makeBone(8, 18), 
    makeBone(18, 19), 
    makeBone(19, 20), 
    makeBone(8, 15), 
    makeBone(15, 16), 
    makeBone(16, 17), 
    makeBone(26, 4), 
    makeBone(4, 3),   
    makeBone(3, 2),   
    makeBone(2, 1),   
    makeBone(1, 55),  
    makeBone(55, 60), 
    makeBone(60, 56), 
    makeBone(56, 57), 
    makeBone(57, 58), 
    makeBone(58, 59), 
    makeBone(1, 49),  
    makeBone(49, 54), 
    makeBone(54, 50), 
    makeBone(50, 51), 
    makeBone(51, 52), 
    makeBone(52, 53) 
};

inline void DrawBones(SDK::USkeletalMeshComponent* mesh, SDK::APlayerController* controller, float ESP_color[3], bool bRainbowMode = false, bool bVisibility = false)
{
	if (globals::rainbow && globals::rainbowESP && bRainbowMode)
	{
		ESP_color = globals::rainbowColor;
	}
	else if (bVisibility)
	{
		if (isVIsible)
			ESP_color = GUI_Colors::Visible;
		else
			ESP_color = GUI_Colors::NotVisible;
	}

	for (int i = 0; i < bones_map.size(); i++)
	{
		SDK::FVector bone_location1 = mesh->GetSocketLocation(mesh->GetBoneName(bones_map[i].start));
		SDK::FVector bone_location2 = mesh->GetSocketLocation(mesh->GetBoneName(bones_map[i].end));

		SDK::FVector2D bone1_w2s{};
		SDK::FVector2D bone2_w2s{};

		if (controller->ProjectWorldLocationToScreen(bone_location1, &bone1_w2s, false) &&
			controller->ProjectWorldLocationToScreen(bone_location2, &bone2_w2s, false))
		{
			ESP::DrawLine(bone1_w2s, bone2_w2s, ESP_color, 1.f, bRainbowMode, bVisibility, true);
		}
	}
}

constexpr float PI = 3.141592653589793236;

std::vector<SDK::FVector2D> generateCirclePoints(const SDK::FVector& head, float radius, SDK::APlayerController* Controller) {
	std::vector<SDK::FVector2D> circlePoints;

	int numPoints = 36; 
	float angleIncrement = (2 * PI) / numPoints;

	for (int i = 0; i < numPoints; ++i) {
		float angle = angleIncrement * i;
		float x = head.X + radius * cos(angle);
		float y = head.Y + radius * sin(angle);
		float z = head.Z;


		SDK::FVector2D projectedPoint{};
		if (Controller->ProjectWorldLocationToScreen(SDK::FVector{ x, y, z }, &projectedPoint, false))
		{
			circlePoints.push_back(projectedPoint);
		}
	}

	return circlePoints;
}
std::vector<SDK::FVector2D> generateBox3DPoints(const SDK::FVector& head, float radius, SDK::APlayerController* Controller) {
	std::vector<SDK::FVector2D> circlePoints;

	int numPoints = 4;
	float angleIncrement = (2 * PI) / numPoints;

	for (int i = 0; i < numPoints; ++i) {
		float angle = angleIncrement * i;
		float x = head.X + radius * cos(angle);
		float y = head.Y + radius * sin(angle);
		float z = head.Z;


		SDK::FVector2D projectedPoint{};
		if (Controller->ProjectWorldLocationToScreen(SDK::FVector{ x, y, z }, &projectedPoint, false))
		{
			circlePoints.push_back(projectedPoint);
		}
	}

	return circlePoints;
}

inline void DrawCircle3D(const std::vector<SDK::FVector2D>& circlePoints, float ESP_color[3], bool bRainbowMode = false, bool bVisibility = false, bool outline = false)
{

	if (globals::rainbow && globals::rainbowESP && bRainbowMode)
	{
		ESP_color = globals::rainbowColor;
	}
	else if (bVisibility)
	{
		if (isVIsible)
			ESP_color = GUI_Colors::Visible;
		else
			ESP_color = GUI_Colors::NotVisible;
	}

	if (circlePoints.size() <= 2) return;

	for (int i = 0; i < circlePoints.size()-1; i++)
	{
		SDK::FVector2D pointA = circlePoints[i];
		SDK::FVector2D pointB = circlePoints[i+1];

		if (i == circlePoints.size() - 2)
		{
			SDK::FVector2D point1 = circlePoints[i+1];
			SDK::FVector2D point2 = circlePoints[0];
			if (!outline)
				ESP::DrawLine(point1, point2, ESP_color, 1.f, bRainbowMode, bVisibility);
			else
				ESP::DrawLine(point1, point2, ESP_color, 1.f, bRainbowMode, bVisibility, true);
		}
		if (!outline)
			ESP::DrawLine(pointA, pointB, ESP_color, 1.f, bVisibility, bRainbowMode);
		else
			ESP::DrawLine(pointA, pointB, ESP_color, 1.f, bVisibility, bRainbowMode, true);
	}
}

inline void DrawPill3D(const std::vector<SDK::FVector2D>& circleA, const std::vector<SDK::FVector2D>& circleB, float ESP_color[3], bool bRainbowMode = false, bool bVisibility = false, bool outline = false)
{
	if (circleA.size() <= 2) return;
	if (circleB.size() <= 2) return;

	auto min = (circleA.size() < circleB.size() ? circleA.size() : circleB.size());

	if (globals::rainbow && globals::rainbowESP && bRainbowMode)
	{
		ESP_color = globals::rainbowColor;
	}
	else if (bVisibility)
	{
		if (isVIsible)
			ESP_color = GUI_Colors::Visible;
		else
			ESP_color = GUI_Colors::NotVisible;
	}

	for (int i = 0; i < min; i++)
	{
		SDK::FVector2D posA = circleA[i];
		SDK::FVector2D posB = circleB[i];

		if (!outline)
			ESP::DrawLine(posA, posB, ESP_color, 1.f, bRainbowMode, bVisibility);
		else
			ESP::DrawLine(posA, posB, ESP_color, 1.f, bRainbowMode, bVisibility, true);
	}
}

inline SDK::FName StrToName(const wchar_t* str)
{
	return SDK::UKismetStringLibrary::Conv_StringToName(SDK::FString(TEXT(str)));
}
inline SDK::FLinearColor FloatToColor(float color[3])
{
	return SDK::FLinearColor{ color[0], color[1], color[2] };
}

inline void ApplyChams(SDK::USkeletalMeshComponent* mesh, SDK::UMaterialInstanceDynamic* material, float color[3], bool bRainbowColor, bool bVisivilityCheck, bool isvisible)
{
	auto Mats = mesh->GetMaterials();

	if (bRainbowColor && globals::rainbow && globals::rainbowChams)
	{
		material->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(globals::rainbowColor));
		for (int t = 0; t < Mats.Num(); t++)
		{
			if (Mats[t])
			{
				mesh->SetMaterial(t, material);
			}
		}
	}
	else
	{
		if (bVisivilityCheck && globals::ChamsVisible)
		{
			if (isvisible)
			{
				ChamsMatVisible->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(GUI_Colors::Visible));

				for (int t = 0; t < Mats.Num(); t++)
				{
					if (Mats[t])
					{
						mesh->SetMaterial(t, ChamsMatVisible);
					}
				}
			}
			else
			{
				ChamsMatNotVisible->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(GUI_Colors::NotVisible));

				for (int t = 0; t < Mats.Num(); t++)
				{
					if (Mats[t])
					{
						mesh->SetMaterial(t, ChamsMatNotVisible);
					}
				}
			}			
		}
		else
		{
			if (globals::WeaponChamsInvisible)
				material->SetVectorParameterValue(StrToName(L"Color"), SDK::FLinearColor{0.f, 0.f, 0.f});
			else
				material->SetVectorParameterValue(StrToName(L"Color"), FloatToColor(color));
			for (int t = 0; t < Mats.Num(); t++)
			{
				if (Mats[t])
				{
					mesh->SetMaterial(t, material);
				}
			}
		}
	}	
}

inline bool IsBadPoint(SDK::UGameInstance* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}
inline bool IsBadPoint(SDK::ULocalPlayer* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}
inline bool IsBadPoint(SDK::APlayerController* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}
inline bool IsBadPoint(SDK::APlayerState* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}
inline bool IsBadPoint(SDK::UWorld* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}
inline bool IsBadPoint(SDK::AGameStateBase* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}
inline bool IsBadPoint(SDK::UProjectileMovementComponent* ptr)
{
	std::uintptr_t Pointer = reinterpret_cast<std::uintptr_t>(ptr);

	if ((Pointer < 0xFFFFFFFFFFULL) || (Pointer > 0x2FFFFFFFFFFULL))
		return true;

	else return false;
}


inline void StartRainbowColor()
{
	constexpr float speed = 10.f;
	auto currentTime = std::chrono::steady_clock::now();
	static auto startTime = currentTime;

	float elapsedTime = std::chrono::duration<float>(currentTime - startTime).count();
	float time = elapsedTime * speed / 2 * PI;

	float r = (sin(time) + 1) / 2;
	float g = (sin(time + 2 * PI / 3) + 1) / 2;
	float b = (sin(time + 4 * PI / 3) + 1) / 2;

	globals::rainbowColor[0] = r;
	globals::rainbowColor[1] = g;
	globals::rainbowColor[2] = b;
}



