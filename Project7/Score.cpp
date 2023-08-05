//
//  Score.cpp
//  Bunco
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// attempted TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score( Move move, Move answer )
{
    std::string copy = "";
    for (int i = 0; i < 5; i++)
    {
        copy = copy + answer.getPiece(i).getLetterAsString();
    }
    
    for (int i = 0; i <5; i++)
    {
        if (move.getPiece(i).getLetter()!=answer.getPiece(i).getLetter())
        {
            array[ i ] = WRONG;
        }
    }
    
    for (int i = 0; i <5; i++)
    {
        if (move.getPiece(i).getLetter()==answer.getPiece(i).getLetter())
        {
            array[ i ] = RIGHT;
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        if (array[i] == RIGHT)
            copy[i]='.';
    }
    
    for (int i = 0; i < 5; i++)
    {
        if (array[i]==WRONG)
        {
            
            int j = 0;
            while (j < 5 && move.getPiece(i).getLetterAsString()[0]!= copy[j])
            {
                j++;
            }
            
            if (j <5)
            {
                copy[j]='.';
                array[i]=MAYBE;
            }
        }
    }
    
}







//// attempted TODO comparing the played move to the answer move,
////      build the ANSWER array of this Score
//Score::Score( Move move, Move answer )
//{
//    for (int i = 0; i <5; i++)
//    {
//        if (move.getPiece(i).getLetter()!=answer.getPiece(i).getLetter())
//        {
//            array[ i ] = WRONG;
//        }
//    }
//
//    for (int i = 0; i <5; i++)
//    {
//        if (move.getPiece(i).getLetter()==answer.getPiece(i).getLetter())
//        {
//            array[ i ] = RIGHT;
//        }
//    }
//
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            if (move.getPiece(i).getLetterAsString()==answer.getPiece(j).getLetterAsString() && array[i]!=RIGHT)
//            {
//
//                array[ i ] = MAYBE;
//            }
//        }
//    }
//
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = i+1; j < 5; j++)
//        {
//            if ((array[i]==MAYBE && array[j]==MAYBE) && move.getPiece(i).getLetterAsString()==move.getPiece(j).getLetterAsString())
//            {
//
//                array[ j ] = WRONG;
//            }
//        }
//    }
//
//}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// ATTEMPTED TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        if (array[i]==WRONG || array[i]==MAYBE)
            return false;
    }
    
    return true;
}

}
