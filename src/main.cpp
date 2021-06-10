#include <iostream>
#include "windows.h"
#include <chrono>
#include <thread>

#include "terminal.h"
#include "golgrid.h"
#include "grid.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    GOLGrid g;
    g.loadGrid("assets/gol2.txt");

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    unsigned consoleWidth = 16*g.getWidth()+60;
    unsigned consoleHeight = 16*g.getHeight()+75+50;

    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, consoleWidth, consoleHeight, FALSE);


    int epoch = 0;
    while(1){
        GetWindowRect(console, &ConsoleRect);
        //MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 16*g.getWidth()+60, 16*g.getHeight()+75+50, FALSE);
        if(ConsoleRect.right-ConsoleRect.left != consoleWidth){
            consoleWidth = ConsoleRect.right-ConsoleRect.left;
            g.setWidth((consoleWidth-60)/16);
        }
        if(ConsoleRect.bottom-ConsoleRect.top != consoleHeight){
            consoleHeight = ConsoleRect.bottom-ConsoleRect.top;
            g.setHeight((consoleHeight-75-50)/16);
        }
        /*std::cout << " WIDTH  : " << ConsoleRect.right - ConsoleRect.left << "  |  "
                  << " HEIGHT : " << ConsoleRect.bottom - ConsoleRect.top << std::endl;
        
        std::cout << " GWIDTH  : " << g.getWidth() << "  |  "
                  << " GHEIGHT : " << g.getHeight() << std::endl;*/

        g.displayGrid();
        g.generateNextGrid();
        std::cout << " Epoch : " << epoch++;
        std::cout << std::endl;
        std::cout << " Ctrl + C to EXIT " ;
        //system("pause");
        //for(int i=0;i<1000000;i++);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        system("cls");
    }
    
    system("pause");
    return 0;
}