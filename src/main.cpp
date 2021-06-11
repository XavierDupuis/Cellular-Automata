#include <iostream>
#include "windows.h"
#include <chrono>
#include <thread>

#include "terminal.h"
#include "grid.h"
#include "golgrid.h"
#include "antgrid.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    HWND console = GetConsoleWindow();
    SetConsoleTitle((LPCTSTR)("Cellular Automata"));
    SetConsoleTextAttribute(console, 0xFFFF);

    ANTGrid g;
    unsigned option = 0;
    while(!option){
        std::cout << " 1) Conway's Game of Life" << std::endl
                  << " 2) Langdon's Ant" << std::endl
                  << " > ";
        std::cin >> option;
        switch (option)
        {
        case 1: g.loadGrid("assets/gol2.txt");
                break;
        case 2: g.loadGrid("assets/ant.txt");
                break;
        default:
                break;
        }
    }
    unsigned steps = 1;
    std::cout << "Steps per Update (default = 1) : " << std::endl
              << " > ";
    std::cin >> steps;

    RECT ConsoleRect;
    unsigned consoleWidth = 16*g.getWidth()+60;
    unsigned consoleHeight = 16*g.getHeight()+75+50;

    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, consoleWidth, consoleHeight, FALSE);

    int epoch = 0;
    while(1){
        GetWindowRect(console, &ConsoleRect);
        if(ConsoleRect.right-ConsoleRect.left != consoleWidth){
            consoleWidth = ConsoleRect.right-ConsoleRect.left;
            g.setWidth((consoleWidth-60)/16);
        }
        if(ConsoleRect.bottom-ConsoleRect.top != consoleHeight){
            consoleHeight = ConsoleRect.bottom-ConsoleRect.top;
            g.setHeight((consoleHeight-75-50)/16);
        }

        g.displayGrid();
        for(unsigned i = 0; i < steps; i++){
            g.generateNextGrid();
        }
        std::cout << " Epoch : " << steps * epoch++;
        std::cout << std::endl;
        std::cout << " Ctrl + C to EXIT " ;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        system("cls");
    }
    
    system("pause");
    return 0;
}