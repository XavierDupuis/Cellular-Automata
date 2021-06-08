#include <iostream>
#include "windows.h"

#include "terminal.h"
#include "grid.h"

/*int main() {*/
    /*std::cout << "asd";
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 400, 400, FALSE);*/
    //textbackgroundRGB(200,200,200);
    //textcolorRGB(200,200,200);


      /*HANDLE  hConsole;
	int k;
	
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);*/

  // you can loop k higher to see more color choices
  /*for(k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    std::cout << k << " I want to be nice today!" << std::endl;
  }*/
  /*std::cout << "TEESST" << std::endl;
  unsigned short value = 0x0101;
  SetConsoleTextAttribute(hConsole, value);
  std::cout << "TEESST" << std::endl;*/

    /*Terminal t;
    std::cout << "not blue" << std::endl;
    t.colorBlue();
    std::cout << "blue" << std::endl;*/

    /*HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    WINDOW_BUFFER_SIZE_RECORD
    //MoveWindow(t, 100,100,100,100,TRUE);
    std::cout << "not blue" << std::endl;
    unsigned short value = 0x0101;
    //SetConsoleTextAttribute(t, value);
    std::cout << "blue" << std::endl;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            std::cout << BLOCK;
        }
        std::cout << std::endl;
    }*/

    /*RECT ConsoleRect;
	GetWindowRect(t, &ConsoleRect); 
    MoveWindow(t, ConsoleRect.left, ConsoleRect.top, 400, 400, FALSE);*/
  

    /*system ("pause");
}*/

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    double charWidth = 10;
    double charHeight = 18;
    unsigned nWidth = 50, nHeight = 25;
 
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, nWidth*charWidth, (nHeight+8)*charHeight, FALSE);
    std::cout << " TEST " << std::endl;
    
    /*std::cout << " T : " << ConsoleRect.top << std::endl 
              << " B : " << ConsoleRect.bottom << std::endl 
              << " L : " << ConsoleRect.left << std::endl 
              << " R : " << ConsoleRect.right << std::endl
              << " WIDTH  : " << ConsoleRect.right - ConsoleRect.left << std::endl
              << " HEIGHT : " << ConsoleRect.bottom - ConsoleRect.top << std::endl;
    for(int i = 0; i < nHeight; i++) {
        for(int j = 0; j < nWidth; j++) {
            std::cout << BLOCK;
        }
        std::cout << std::endl;
    }*/
    Grid g;
    g.loadGrid("assets/gol.txt");

    g.displayGrid();
    g.generateNextGrid();
    g.displayGrid();
    

    system("pause");
    return 0;
}