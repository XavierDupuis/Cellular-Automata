#include "windows.h"

class Terminal {
public:
    double charWidth = 10;
    double charHeight = 18;
    unsigned nWidth = 50, nHeight = 25;
    unsigned _height, _width;
    Terminal(int width, int height): _width(width), _height(height) {}
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    char BLOCK = 219;
    bool colorBlue(){
        unsigned short value = 0x0101;
        return SetConsoleTextAttribute(t, value);
    }
    void fillup(){
        for(int i = 0; i < _height; i++) {
            for(int j = 0; j < _width; j++) {
                std::cout << BLOCK;
            }
            std::cout << std::endl;
        }
    }
};