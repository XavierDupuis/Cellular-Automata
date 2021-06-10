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
    std::pair<unsigned, unsigned> currentCell = {11,7};
    std::pair<unsigned, unsigned> nextCell = {11,6};

    bool getCellState(unsigned x, unsigned y){
        return _previousValues.at(y).at(x);
    };

    bool getCellState(std::pair<unsigned, unsigned> cell){
        return getCellState(cell.first, cell.second);
    };

    void generateNextGrid(){
        _previousValues = cloneValues();
        currentCell = nextCell;
        /*nextCell = (getCellState(currentCell)) ? 
            {currentCell.first, currentCell.first} :
            {currentCell.first, currentCell.first};*/
    }
};

#endif // ANTGRID_H