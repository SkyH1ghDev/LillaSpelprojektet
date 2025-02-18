#include "ImGuiHelper.hpp"

#include <windows.h>

std::unordered_map<int, ImGuiKeyWrapper> ImGuiHelper::m_validKeys =
    {
        
		// KEYBOARD
        {ImGuiKey_Escape, {"Escape", VK_ESCAPE}}, {ImGuiKey_Tab, {"Tab", VK_TAB}}, {ImGuiKey_CapsLock, {"Caps Lock", VK_CAPITAL}}, {ImGuiKey_LeftShift, {"LeftShift", VK_LSHIFT}}, {ImGuiKey_LeftCtrl, {"LeftCtrl", VK_LCONTROL}}, {ImGuiKey_Space, {"Space", VK_SPACE}},
		{ImGuiKey_F1, {"F1", VK_F1}}, {ImGuiKey_F2, {"F2", VK_F2}}, {ImGuiKey_F3, {"F3", VK_F3}}, {ImGuiKey_F4, {"F4", VK_F4}}, {ImGuiKey_F5, {"F5", VK_F5}}, {ImGuiKey_F6, {"F6", VK_F6}}, {ImGuiKey_F7, {"F7", VK_F7}}, {ImGuiKey_F8, {"F8", VK_F8}}, {ImGuiKey_F9, {"F9", VK_F9}}, {ImGuiKey_F10, {"F10", VK_F10}}, {ImGuiKey_F11, {"F11", VK_F11}}, {ImGuiKey_F12, {"F12", VK_F12}},

        {ImGuiKey_1, {"1", '1'}}, {ImGuiKey_2, {"2", '2'}}, {ImGuiKey_3, {"3", '3'}}, {ImGuiKey_4, {"4", '4'}}, {ImGuiKey_5, {"5", '5'}}, {ImGuiKey_6, {"6", '6'}}, {ImGuiKey_7, {"7", '7'}}, {ImGuiKey_8, {"8", '8'}}, {ImGuiKey_9, {"9", '9'}}, {ImGuiKey_0, {"0", '0'}},
        {ImGuiKey_Q, {"Q", 'Q'}}, {ImGuiKey_W, {"W", 'W'}}, {ImGuiKey_E, {"E", 'E'}}, {ImGuiKey_R, {"R", 'R'}}, {ImGuiKey_T, {"T", 'T'}}, {ImGuiKey_Y, {"Y", 'Y'}}, {ImGuiKey_U, {"U", 'U'}}, {ImGuiKey_I, {"I", 'I'}}, {ImGuiKey_O, {"O", 'O'}}, {ImGuiKey_P, {"P", 'P'}}, //{ImGuiKey_'Å'},
        {ImGuiKey_A, {"A", 'A'}}, {ImGuiKey_S, {"S", 'S'}}, {ImGuiKey_D, {"D", 'D'}}, {ImGuiKey_F, {"F", 'F'}}, {ImGuiKey_G, {"G", 'G'}}, {ImGuiKey_H, {"H", 'H'}}, {ImGuiKey_J, {"J", 'J'}}, {ImGuiKey_K, {"K", 'K'}}, {ImGuiKey_L, {"L", 'L'}}, //{ImGuiKey_'Ö'}, {ImGuiKey_'Ä'},
        {ImGuiKey_Z, {"Z", 'Z'}}, {ImGuiKey_X, {"X", 'X'}}, {ImGuiKey_C, {"C", 'C'}}, {ImGuiKey_V, {"V", 'V'}}, {ImGuiKey_B, {"B", 'B'}}, {ImGuiKey_N, {"N", 'N'}}, {ImGuiKey_M, {"M", 'M'}},

		// MOUSE
		{ImGuiKey_MouseLeft, {"Mouse Left", VK_LBUTTON}}, {ImGuiKey_MouseRight, {"Mouse Right", VK_RBUTTON}}, {ImGuiKey_MouseMiddle, {"Mouse 3", VK_MBUTTON}}, {ImGuiKey_MouseX1, {"Mouse 4", VK_XBUTTON1}}, {ImGuiKey_MouseX2, {"Mouse 5", VK_XBUTTON2}}
    };
