#pragma once
#include <cstdint>
#include <vector>
#include "SDK.hpp"
#include "vector.h"

namespace globals
{
	inline bool ESP_Box = false;
	inline bool ESP_3DBox = false;
	inline bool ESP_BoxCornered = false;
	inline bool ESP_Names = false;
	inline bool ESP_Snaplines = false;
	inline bool ESP_AimLine = true;
	inline bool ESP_VisibleLIne = false;
	inline bool ESP_Skeleton = true;
	inline float ESP_Distance = 7000.f;
	inline bool ESP_Distance_bool = false;
	inline bool ESP_FeetCircle3D = true;
	inline bool ESP_Pill3D = false;
	inline bool ESP_HealthBar = true;
	inline bool ESP_DistanceText = false;
	inline bool ESP_WeaponText = false;

	inline bool Chams = true;
	inline float ChamsColor[3]{ 1.f, 0.f, 1.f };
	inline bool WeaponChams = true;
	inline bool WeaponChamsInvisible = false;
	inline float ChamsWeaponColor[3]{ 0.f, 1.f, 0.f };
	inline bool ChamsVisible = true;
	inline bool EnemieWeaponChams = true;
	inline float EnemieWeaponChamsColor[3]{ 0.f, 1.f, 1.f };

	inline float rainbowColor[3]{};
	inline bool rainbow = true;
	inline bool rainbowChams = false;
	inline bool rainbowESP = false;

	inline bool ShowMouse = true;
	inline bool aimbot = true;
	inline bool DrawFov = true;
	inline float aimbot_FOV = 1000.f;
	inline bool VisCheckAim = true;

	inline bool superSpeed = false;
	inline float Speed_force = 5000.f;
	inline bool Fly = false;
	inline bool FOVChanger = false;
	inline float FOVCHangerValue = 140.f;
	inline bool InfiniteAmmo = false;
	inline bool NoGravity = false;
	inline bool GodMode = false;
	inline bool NoRecoil = true;
	inline bool InstaFireRate = false;
	inline float FireRate = 0.05f;
	inline bool BulletsPerShoot_bool = false;
	inline int BulletsPerShoot = 2;
	inline bool PlayerTp = false;

	inline bool TeamCheck = true;
	inline bool ShowFPS = true;
	inline bool Croshhair = true;
	inline float CroshhairSize = 3.f;
	inline float CroshhairWidth = 1.f;
	inline float CroshhairColor[3]{ 255.f, 0.f, 0.f };
}

inline SDK::UEngine* Engine{};
inline SDK::UWorld* World{};
inline SDK::AActor* actor{};
inline SDK::FVector location{};
inline SDK::APlayerController* MyController{};
inline SDK::TArray<SDK::AActor*> actors{};
inline SDK::FVector2D Top{};
inline SDK::FVector2D Bottom{};
inline SDK::FVector feet_pos{};
inline SDK::FVector head_pos{};
inline SDK::AActor* LocalP{};
inline ImDrawList* draw_list{};
inline bool isVIsible{};
float aimbot_distance{};
SDK::FVector closest_actor_head{};
SDK::FVector closest_actor_TP{};
SDK::FVector2D closest_actor_headw2s{};
bool closest_actor_visible{};
SDK::APawn* MyPawn{};
std::vector<SDK::FVector2D> circlePoints_Feet{};
std::vector<SDK::FVector2D> circlePoints_Head{};
std::vector<SDK::FVector2D> Box3DHead{};
std::vector<SDK::FVector2D> Box3DFeets{};
SDK::FVector AimbotBone{};
const SDK::APlayerState* ent{};
SDK::TArray<class SDK::APlayerState*> PlayerArray{};
SDK::AHDPlayerCharacter* CharacterClass{};
SDK::UMaterial* TransparentMaterial{};
SDK::UMaterial* WireframeMaterial{};
SDK::UMaterial* FlameMaterial{};
SDK::UMaterialInstanceDynamic* ChamsMat{};
SDK::UMaterialInstanceDynamic* ChamsMatVisible{};
SDK::UMaterialInstanceDynamic* ChamsMatNotVisible{};
SDK::UMaterialInstanceDynamic* WeaponChamsMat{};
SDK::UMaterialInstanceDynamic* EnemieWEaponMat{};

namespace GUI_Colors
{
	inline float Box[3]{1.f, 0.f, 0.f};
	inline float Snaplines[3]{ 0.f, 1.f, 0.f };
	inline float Text[3]{ 1.f, 1.f, 1.f };
	inline float Skeleton[3]{ 1.f, 1.f, 1.f };
	inline float Visible[3]{ 0.f, 0.f, 1.f };
	inline float NotVisible[3]{ 1.f, 0.f, 0.f };
}

namespace Colors
{
	inline float White[3]{ 1.f, 1.f, 1.f };
	inline float Black[3]{ 0.f, 0.f, 0.f };
	inline float Red[3]{ 1.f, 0.f, 0.f };
	inline float Green[3]{ 0.f, 1.f, 0.f };
	inline float Blue[3]{ 0.f, 0.f, 1.f };
	inline float Cian[3]{ 0.f, 1.f, 1.f };
	inline float Pink[3]{ 1.f, 0.f, 1.f };
	inline float Yellow[3]{ 1.f, 1.f, 0.f };
}