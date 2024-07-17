#include "ui.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

bool showMenu = false;
bool godMode = false;

void InitializeImGui() {
    ImGui::CreateContext();
    ImGui_ImplWin32_Init(GetActiveWindow());
    ImGui_ImplDX9_Init(GetDevice());
}

void RenderImGui() {
    if (!showMenu) return;

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("GeoBoost Menu");

    ImGui::Text("GeoBoost");
    if (ImGui::Button("Toggle God Mode")) {
        godMode = !godMode;
    }

    ImGui::End();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void ToggleMenu() {
    showMenu = !showMenu;
}
