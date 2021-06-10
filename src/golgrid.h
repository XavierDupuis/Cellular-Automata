/**
 * @file golgrid.h
 * @brief based on Conway's Game of Life
 *        https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 * @version 0.1
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021
 */

#ifndef GOLGRID_H
#define GOLGRID_H

#include "grid.h"

class GOLGrid: public Grid{
public:
   unsigned getAliveNeighboors(unsigned x, unsigned y){
        unsigned sum = 0;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                sum += _previousValues.at((y + j + getHeight())%getHeight()).at((x + i + getWidth())%getWidth()); 
            }
        }
        return sum -= _previousValues.at(y).at(x);
  };

   void generateNextGrid(){
        _previousValues = cloneValues();
        for(unsigned i = 0; i < getHeight(); i++){
            for(unsigned j = 0; j < getWidth(); j++){
                unsigned aliveNeighboors = getAliveNeighboors(j,i);
                if(_previousValues[i][j] == true){
                    _currentValues.at(i).at(j) = (aliveNeighboors == 2 || aliveNeighboors == 3);
                }
                else{
                    _currentValues.at(i).at(j) = (aliveNeighboors == 3);
                }
            }
        }
   }
};

#endif // GOLGRID_H