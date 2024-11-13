#include <iostream>
#include <Windows.h>

#include "CentrerTexte.h"

using namespace std;

void centrerTexte(std::string text) { // Source : https://stackoverflow.com/questions/45582095/c-how-can-i-center-text-output
    // Pour styliser le choix de l'utilisateur, pas de rapport avec les classes et la POO
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);
    COORD NewSBSize = lpScreenInfo->dwSize;
    if (NewSBSize.X > text.size()) {
        int newpos = ((NewSBSize.X - text.size()) / 2);
        for (int i = 0; i < newpos; i++) cout << " ";
    }
    cout << text << endl;
}