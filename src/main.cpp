#include <iostream>
#include "windows.h"

#include "terminal.h"
#include "golgrid.h"
#include "grid.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    double charWidth = 10;
    double charHeight = 18;
    unsigned nWidth = 50, nHeight = 25;
 
    GetWindowRect(console, &ConsoleRect);
    //MoveWindow(console, ConsoleRect.left, ConsoleRect.top, nWidth*charWidth, (nHeight+8)*charHeight, FALSE);
    std::cout << " TEST " << std::endl;
    
    std::cout << " T : " << ConsoleRect.top << std::endl 
              << " B : " << ConsoleRect.bottom << std::endl 
              << " L : " << ConsoleRect.left << std::endl 
              << " R : " << ConsoleRect.right << std::endl
              << " WIDTH  : " << ConsoleRect.right - ConsoleRect.left << std::endl
              << " HEIGHT : " << ConsoleRect.bottom - ConsoleRect.top << std::endl;
    for(int i = 0; i < nHeight; i++) {
        for(int j = 0; j < nWidth; j++) {
            std::cout << char(BLOCK);
        }
        std::cout << std::endl;
    }

    ///////////////////

    GOLGrid g;
    g.loadGrid("assets/gol.txt");
    /*g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    g.generateNextGrid();*/

    int epoch = 0;
    while(1){
        g.displayGrid();
        g.generateNextGrid();
        std::cout << " Epoch : " << epoch++;
        std::cout << std::endl;
        std::cout << " Ctrl + C to EXIT " ;
        //system("pause");
        for(int i=0;i<100000000;i++);
        system("cls");
    }
    
    system("pause");
    return 0;
}