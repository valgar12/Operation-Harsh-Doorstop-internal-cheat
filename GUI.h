#pragma once
#include "SDK.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "globals.h"
#include "vector.h"
#include <array>


inline void Draw_GUI()
{
	ImGui::Begin("valgar1");
	if (ImGui::BeginTabBar("tabs"))
	{
		if (ImGui::BeginTabItem("Aim"))
		{
			ImGui::Checkbox("Aimbot", &globals::aimbot);
			ImGui::SliderFloat("FOV", &globals::aimbot_FOV, 1.f, 3000.f);
			ImGui::Checkbox("Draw FOV", &globals::DrawFov);
			ImGui::Checkbox("Vis check", &globals::VisCheckAim);

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Exploits"))
		{
			ImGui::Checkbox("Super Speed", &globals::superSpeed);
			ImGui::SliderFloat("Speed Power", &globals::Speed_force, 1000.f, 10000.f);
			ImGui::Checkbox("Fly", &globals::Fly);
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			ImGui::Checkbox("God Mode", &globals::GodMode);
			ImGui::Checkbox("Infinite Ammo", &globals::InfiniteAmmo);
			ImGui::Checkbox("No Recoil", &globals::NoRecoil);
			ImGui::Checkbox("Bullets Per Burst", &globals::BulletsPerShoot_bool);
			ImGui::SliderInt("Bullets Per Burst", &globals::BulletsPerShoot, 1, 4);
			ImGui::Checkbox("Insta FireRate", &globals::InstaFireRate);
			ImGui::SliderFloat("Fire Rate", &globals::FireRate, 0.001f, 0.05f);
			ImGui::Checkbox("Player TP", &globals::PlayerTp);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Visuals"))
		{
			ImGui::Checkbox("Chams", &globals::Chams);
			ImGui::SameLine();
			ImGui::ColorEdit3("##Chams color", globals::ChamsColor, ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox("Visible Chams", &globals::ChamsVisible);
			ImGui::Checkbox("Weapon Chams", &globals::WeaponChams);
			ImGui::SameLine();
			ImGui::ColorEdit3("##Weapon Chams color", globals::ChamsWeaponColor, ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox("Enemie Weapon Chams", &globals::EnemieWeaponChams);
			ImGui::SameLine();
			ImGui::ColorEdit3("##Enemie Weapons Chams color", globals::EnemieWeaponChamsColor, ImGuiColorEditFlags_NoInputs);

			ImGui::Separator();
			ImGui::Checkbox("Show mouse", &globals::ShowMouse);
			ImGui::Checkbox("Box", &globals::ESP_Box);
			ImGui::Checkbox("Corenered Box", &globals::ESP_BoxCornered);
			ImGui::Checkbox("3D Box", &globals::ESP_3DBox);
			ImGui::Checkbox("Names", &globals::ESP_Names);
			ImGui::Checkbox("Snaplines", &globals::ESP_Snaplines);
			ImGui::Checkbox("Aim Line", &globals::ESP_AimLine);
			ImGui::Checkbox("Visible Line", &globals::ESP_VisibleLIne);
			ImGui::Checkbox("Skeleton", &globals::ESP_Skeleton);
			ImGui::Checkbox("Health Bar", &globals::ESP_HealthBar);
			ImGui::Checkbox("Distance Text", &globals::ESP_DistanceText);
			ImGui::Checkbox("Feet 3D Circle", &globals::ESP_FeetCircle3D);
			ImGui::Checkbox("3D Pill", &globals::ESP_Pill3D);
			ImGui::Checkbox("Distance", &globals::ESP_Distance_bool);
			if (globals::ESP_Distance_bool)
				ImGui::SliderFloat("Distance", &globals::ESP_Distance, 1, 50000);
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			ImGui::Text("Box color");
			ImGui::SameLine();
			ImGui::ColorEdit3("##Box color", GUI_Colors::Box, ImGuiColorEditFlags_NoInputs);
			ImGui::Text("Snaplines color");
			ImGui::SameLine();
			ImGui::ColorEdit3("##Snaplines color", GUI_Colors::Snaplines, ImGuiColorEditFlags_NoInputs);
			ImGui::Text("Text color");
			ImGui::SameLine();
			ImGui::ColorEdit3("##Text color", GUI_Colors::Text, ImGuiColorEditFlags_NoInputs);
			ImGui::Text("Skeleton color");
			ImGui::SameLine();
			ImGui::ColorEdit3("##Skeleton color", GUI_Colors::Skeleton, ImGuiColorEditFlags_NoInputs);
			ImGui::Text("Visible color");
			ImGui::SameLine();
			ImGui::ColorEdit3("##Visible color", GUI_Colors::Visible, ImGuiColorEditFlags_NoInputs);
			ImGui::Text("Not Visible color");
			ImGui::SameLine();
			ImGui::ColorEdit3("##Not Visible color", GUI_Colors::NotVisible, ImGuiColorEditFlags_NoInputs);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Misc"))
		{
			ImGui::Checkbox("Team Check", &globals::TeamCheck);
			ImGui::Checkbox("Rainbow Mode", &globals::rainbow);
			ImGui::Checkbox("Rainbow ESP", &globals::rainbowESP);
			ImGui::Checkbox("Rainbow Chams", &globals::rainbowChams);
			ImGui::Checkbox("Show FPS", &globals::ShowFPS);
			ImGui::Checkbox("Crosshair", &globals::Croshhair);
			ImGui::SameLine();
			ImGui::ColorEdit3("##Crosshair color", globals::CroshhairColor, ImGuiColorEditFlags_NoInputs);
			if (globals::Croshhair)
			{
				ImGui::SliderFloat("Crosshair size", &globals::CroshhairSize, 1.f, 20.f);
				ImGui::SliderFloat("Crosshair width", &globals::CroshhairWidth, 1.f, 5.f);
			}
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}

inline void SetColorsFlags()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.FrameBorderSize = 1.f;
	style.TabBorderSize = 1.f;
	style.WindowTitleAlign.x = 0.50f;
	style.WindowPadding = ImVec2(5, 5);
	style.WindowRounding = 4.0f;
	style.FramePadding = ImVec2(6, 6);
	style.FrameRounding = 2.0f;
	style.ItemSpacing = ImVec2(12, 8);
	style.ItemInnerSpacing = ImVec2(8, 6);
	style.IndentSpacing = 25.0f;
	style.ScrollbarSize = 15.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 20.0f;
	style.GrabRounding = 3.0f;

	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.01f, 0.91f, 0.96f, 0.94f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.04f, 0.04f, 0.04f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.38f, 0.09f, 0.89f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.00f, 1.00f, 0.31f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.43f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.38f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.45f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.43f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.00f, 0.87f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.38f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.84f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.86f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.47f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.49f, 0.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.43f, 0.00f, 1.00f, 0.89f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.77f, 0.06f, 0.98f, 0.80f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.97f, 0.00f, 1.00f, 0.84f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.28f, 0.28f, 0.57f, 0.82f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.35f, 0.35f, 0.65f, 0.84f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.04f, 0.04f, 0.04f, 0.73f);
}
