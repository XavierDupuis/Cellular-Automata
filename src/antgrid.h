/**
 * @file antgrid.h
 * @brief based on Langton's ant
 *        https://en.wikipedia.org/wiki/Langton%27s_ant
 * @version 0.1
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021
 */

#ifndef ANTGRID_H
#define ANTGRID_H

#include "grid.h"

class ANTGrid: public Grid{
public:
    std::pair<unsigned, unsigned> _currentCell = {0,0};
    std::vector<std::pair<unsigned, unsigned>> _directions = 
        { {0,1}, {1,0}, {0,-1}, {-1,0} };
    enum direction {UP,RIGHT,DOWN,LEFT};
    direction _direction = DOWN;

    bool loadGrid(std::string filename, char readBlock = '#'){
        bool isLoaded = Grid::loadGrid(filename, readBlock);
        _currentCell = {getWidth()/2,getHeight()/2};
        return isLoaded;
    }

    bool getCellState(unsigned x, unsigned y){
        return _previousValues.at(y).at(x);
    };

    bool getCellState(std::pair<unsigned, unsigned> cell){
        return getCellState(cell.first, cell.second);
    };

    void generateNextGrid(){
        _previousValues = cloneValues();
        _direction = ( getCellState(_currentCell) ) ? 
            direction((_direction + 1 + 4) % 4) : 
            direction((_direction - 1 + 4) % 4);
        _currentValues.at(_currentCell.second).at(_currentCell.first) = 
            !getCellState(_currentCell);
        _currentCell = {(_currentCell.first  + _directions[_direction].first + getWidth()) %  getWidth(),
                        (_currentCell.second + _directions[_direction].second + getHeight()) %  getHeight()};
    }
};

#endif // ANTGRID_H