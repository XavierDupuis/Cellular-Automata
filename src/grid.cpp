#include "grid.h"

bool Grid::loadGrid(std::string filename){
    std::ifstream f(filename);
    if(!f)
    {
        std::cout << " FILE '" + filename + "' could not be read." << std::endl;
        return false;
    }
    char nextChar;
    std::vector<bool> line;
    unsigned width = 0;
    nextChar = f.get();
    do{
        width++;
        line.push_back(nextChar == _readBlock);
        nextChar = f.get();
    } while(nextChar != '\n');
    _width = width;
    _currentValues.push_back(line);
    while(!ws(f).eof()) {
        line.clear();
        for(unsigned i = 0; i < _width; i++){
            nextChar = f.get();
            line.push_back(nextChar == _readBlock);
        }
        _currentValues.push_back(line);
    }
    _height = _currentValues.size();
    /*std::cout << " CURRENT VALUES " << std::endl;
    for(unsigned i = 0; i < _height; i++){
        for(unsigned j = 0; j < _width; j++){
            std::cout << _currentValues[i][j];
        }
        std::cout << std::endl;
    }*/
    f.close();
    return true;
}

std::vector<std::vector<bool>> Grid::cloneValues() const{
    std::vector<std::vector<bool>> cloneValues;
    for(unsigned i = 0; i < getHeight(); i++){
        cloneValues.push_back(_currentValues.at(i));
    }
    return cloneValues;
}

void Grid::generateNextGrid() {
    _previousValues = cloneValues();

    for(unsigned i = 0; i < getHeight(); i++){
        for(unsigned j = 0; j < getWidth(); j++){
            // BASIC BEHAVIOR 
            if(_previousValues[i][j] == false){
                _currentValues.at(i).at(j) = true;
            }
            else{
               _currentValues.at(i).at(j) = false;
            }
        }
    }
}

void Grid::displayGrid(char block) {
    for(unsigned i = 0; i < getHeight(); i++){
        for(unsigned j = 0; j < getWidth(); j++){
            char newBlock = (_currentValues[i][j]) ? block : ' ';
            std::cout << newBlock;
        }
        std::cout << std::endl;
    }
}
