#include <Windows.h>
#include <thread>
#include <sstream>

void* (*FindPlayerPed)(int) = reinterpret_cast<void* (*)(int)>(0x56E210);
float (*BikeRidingSkill)(void*) = (float(*)(void*))0x5DF510;

void (*SetWantedLevel) (void*, int) = (void (*)(void*, int))0x609F10;

float get_bike_skill();
void loop();

HMODULE self;
void attach() {

    // float skill = -1;
    // skill = get_bike_skill();
    
    // std::stringstream ped_msg;
    // ped_msg << "bike skill: " << skill;
    // MessageBoxA(nullptr, ped_msg.str().c_str(), "suhas", MB_OKCANCEL);

    // get bike riding skill

    loop();

}

void loop() {

    __try {
    while (true) {
        /* Spawn Tank */
        if (GetAsyncKeyState('T') & 0x8000) {
            ((void (*) ())(0x43a4a0)) ();
        }

        /* Spawn police bike */
        if (GetAsyncKeyState('V') & 0x8000) {
            ((void (*) (int)) (0x43A0B0)) (523);
        }

        /* Increase money */
        if (GetAsyncKeyState('O') & 0x8000) {
            int* score = (int*)(0xb7ce50);
            int* score_s = (int*)(0xb7ce54);
            *score = *score + 100000;
            *score_s = *score_s + 100000;     // RACE -- would not update
        }

        Sleep(1000);
    }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        MessageBoxA(nullptr, "Mod crashed", "Exception", MB_OK);
    }
}

float get_bike_skill() {
    __try {
        void* player=  FindPlayerPed(-1);
        return BikeRidingSkill(player);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        MessageBoxA(nullptr, "exception", "exception", MB_OK);
    }
    return -1;
}

void detach() {

}

extern "C" {
__declspec(dllexport) BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        self = hinstDLL;
        std::thread(attach).detach(); break;
    case DLL_PROCESS_DETACH:
        detach(); break;
    }
}
}