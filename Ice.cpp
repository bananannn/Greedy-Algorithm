// Name: Bananannn
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"
#include <utility>
#include <iostream>

int ice(TwoD_Array<int> rooms) {
    int cols = rooms.getNumCols();
    int rows = rooms.getNumRows();
    TwoD_Array<std::pair<int, int>> arr = TwoD_Array<std::pair<int,int>>(cols, rows);
    for( int j = 0; j<cols; j++ ){
        for( int i = 0; i<rows; i++ ){
            // first room
            if( i == 0 && j == 0 ){
                arr.at(i, j) = std::make_pair(rooms.at(i,j), rooms.at(i,j));
            }
            // the first row
            else if( i == 0 ){
                int maxone = MAX( arr.at(i, j-1).second+rooms.at(i,j), 
                             arr.at(i, j-1).first);
                arr.at(i, j) = std::make_pair(maxone, 
                               arr.at(i, j-1).second+rooms.at(i,j));
            }
            // the leftmost column
            else if( j == 0 ){
                int current = arr.at(i-1, j).second+rooms.at(i,j);
                int maxone = MAX( current, 
                             arr.at(i-1,j).first );
                arr.at(i, j) = std::make_pair(maxone, current);
            }
            // the inner rooms
            else{
                int currOne = arr.at(i-1, j).first;
                int currTwo = arr.at(i, j-1).first;
                int path = MIN(currOne, currTwo);
                int currPath = 0;
                if( path == currOne ) currPath = arr.at(i-1,j).second;
                else currPath = arr.at(i, j-1).second;
                if( rooms.at(i,j) > 0 ){
                    path = MAX(currPath+rooms.at(i,j), path);
                }
                currPath += rooms.at(i,j);
                arr.at(i,j) = std::make_pair(path, currPath);
            }
        }
    }
    if( arr.at(rows-1, cols-1).first < 0 ) return 1;
    return arr.at(rows-1,cols-1).first+1;
}
#endif
