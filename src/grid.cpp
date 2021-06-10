#include "grid.h"

void Grid::setWidth(unsigned newWidth) {
    if (newWidth > _width){
        for(unsigned i = 0; i < _height; i++){
            for(unsigned j = _width; j < newWidth; j++){
                _currentValues.at(i).push_back(false);
            }
        }
    }
    else if(newWidth < _width){
        for(unsigned i = 0; i < _height; i++){
            for(unsigned j = newWidth; j < _width; j++){
                _currentValues.at(i).pop_back();
            }
        }
    }
    _width = newWidth;
}

void Grid::setHeight(unsigned newHeight) {
    if (newHeight > _height){
        for(unsigned i = _height; i < newHeight; i++){
            _currentValues.push_back(std::vector<bool>(_width, false));
        }
    }
    else if(newHeight < _height){
        for(unsigned i = newHeight; i < _height; i++){
            _currentValues.pop_back();
        }
    }
    _height = newHeight;
}


bool Grid::loadGrid(std::string filename, char readBlock){
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
        line.push_back(nextChar == readBlock);
        nextChar = f.get();
    } while(nextChar != '\n');
    _width = width;
    _currentValues.push_back(line);
    while(!ws(f).eof()) {
        line.clear();
        for(unsigned i = 0; i < _width; i++){
            nextChar = f.get();
            line.push_back(nextChar == readBlock);
        }
        _currentValues.push_back(line);
    }
    _height = _currentValues.size();
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
    std::cout << char(218);
    for(unsigned i = 0; i < getWidth(); i++){
        std::cout << char(196) << char(196);
    }
    std::cout << char(191);
    std::cout << std::endl;

    for(unsigned i = 0; i < getHeight(); i++){
        std::cout << char(179);
        for(unsigned j = 0; j < getWidth(); j++){
            char newBlock = (_currentValues[i][j]) ? block : ' ';
            std::cout << newBlock << newBlock;
        }
        std::cout << char(179);
        std::cout << std::endl;
    }

    std::cout << char(192);
    for(unsigned i = 0; i < getWidth(); i++){
        std::cout << char(196) << char(196);
    }
    std::cout << char(217);
    std::cout << std::endl;
}
