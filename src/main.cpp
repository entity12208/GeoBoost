#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

// Your existing code...



#include "cheats.h"
#include "ui.h"

DWORD WINAPI MainThread(LPVOID lpReserved) {
    if (MH_Initialize() != MH_OK) {
        return 1;
    }

    InstallCheats();
    InitializeImGui();

    while (!GetAsyncKeyState(VK_END)) {
        if (GetAsyncKeyState(VK_TAB) & 1) {
            ToggleMenu();
        }

        RenderImGui();
    }

    MH_Uninitialize();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
