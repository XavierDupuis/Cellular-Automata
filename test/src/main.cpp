#include <iostream>
#include "windows.h"

#include "../../src/terminal.h"
#include "../../src/grid.h"

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

    Grid g;
    g.loadGrid("../assets/gol.txt");
    int epoch = 0;
    g.displayGrid();
    g.generateNextGrid();

    g.displayGrid();
    g.generateNextGrid();
    system("pause");

    std::cout << "WIDTH ++" << std::endl;
    g.setWidth(30);
    g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    g.generateNextGrid();
    system("pause");

    std::cout << "HEIGHT ++" << std::endl;
    g.setHeight(30);
    g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    g.generateNextGrid();
    system("pause");

    std::cout << "HEIGHT --" << std::endl;
    g.setHeight(3);
    g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    g.generateNextGrid();
    system("pause");


    std::cout << "WIDTH --" << std::endl;
    g.setWidth(3);
    g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    g.generateNextGrid();
    system("pause");


    /*while(1){
        g.displayGrid();
        g.generateNextGrid();
        std::cout << " Epoch : " << epoch++;
        std::cout << std::endl;
        std::cout << " Ctrl + C to EXIT " ;
        for(int i=0;i<100000000;i++);
        system("cls");
    }*/
        
    
    system("pause");
    return 0;
}