// Name: Bananannn
// Sources of Help: https://piazza.com/class/jb8pdrlepuy2ga?cid=883
// https://piazza.com/class/jb8pdrlepuy2ga?cid=902
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include "Tennis.hpp"
#include <algorithm>
#include <iostream>

// For the sort method
bool operation( const Interval i, const Interval j ){
    if( i.start < j.start ){
        return true;
    }
    else if( i.start == j.start ){
        if( i.end < j.end ) return true;
        else return false;
    }
    return false;
}

int tennis(std::vector<Interval> lessons) {
    std::vector<int> myvec;
    std::sort( lessons.begin(), lessons.end(), operation );
    myvec.push_back(lessons[0].end);
    // Find the court for each of the lesson
    for( auto it = lessons.begin()+1; it!=lessons.end(); ++it ){
        int find = 0;
        // check the court available
        for( int i = 0; i<myvec.size(); ++i){

            if( myvec[i] <= it->start ){
                myvec[i] = it->end;
                find = 1;
                break;
            }
        }
        // if no court available, add a court
        if( find == 0 ){
            myvec.push_back(it->end);
        }
    } 
    return myvec.size();
}
#endif
