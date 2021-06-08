#include <iostream>
#include <vector>
#include <fstream>

class Grid {
public:
    Grid() = default;
    Grid(int width, int height): _width(width), _height(height), _currentValues(std::vector<std::vector<bool>>()) {}
    Grid(std::vector<std::vector<bool>> values): _currentValues(values), _width(values[0].size()), _height(values.size()){}
    Grid(const Grid& grid) {
        _currentValues = grid.cloneValues();
        _width = _currentValues[0].size();
        _height = _currentValues.size();
    }

    unsigned getWidth() const  {return _width;}
    unsigned getHeight() const {return _height;}

    char _readBlock = '#';
    char _displayBlock = 219;
    bool loadGrid(std::string filename);
    
    std::vector<bool> getNeighboors(unsigned x, unsigned y){};

    std::vector<std::vector<bool>> cloneValues() const;

    void generateNextGrid();

    void displayGrid(char block = 219);

    std::vector<std::vector<bool>> _currentValues;
    std::vector<std::vector<bool>> _previousValues;
private:

    unsigned _width;
    unsigned _height;
    unsigned _charWidth = 10;
    unsigned _charHeight = 18;
    char BLOCK = 219;
};