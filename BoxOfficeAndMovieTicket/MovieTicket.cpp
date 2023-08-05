//
//  MovieTicket.cpp
//  Project 5
//
//  Created by Ayan Nath on 7/26/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "MovieTicket.h"
using namespace std;

MovieTicket::MovieTicket()
{
    
}

MovieTicket::MovieTicket(string movie, Day day, Time time, Kind kind, Type type)
{
    mMovie = movie;
    mDay = day;
    mTime = time;
    mKind = kind;
    mType = type;
}

string MovieTicket::getMovie()
{
    return mMovie;
}

MovieTicket::Day MovieTicket::getDay()
{
    return mDay;
}

MovieTicket::Time MovieTicket::getTime()
{
    return mTime;
}

MovieTicket::Kind MovieTicket::getKind()
{
    return mKind;
}

MovieTicket::Type MovieTicket::getType()
{
    return mType;
}

bool MovieTicket::isWeekendTicket()
{
    if (mDay==FRIDAY || mDay == SATURDAY || mDay == SUNDAY)
        return true;
    
    return false;
}

bool MovieTicket::isWeekdayTicket()
{
    if (mDay==MONDAY || mDay == TUESDAY || mDay == WEDNESDAY || mDay == THURSDAY)
        return true;
    
    return false;
}

bool MovieTicket::isMatineeTicket()
{
    if (mTime == NOON || mTime == TWOPM || mTime == FOURPM)
        return true;
    
    return false;
}

bool MovieTicket::isEveningTicket()
{
    if (mTime == SIXPM || mTime == EIGHTPM || mTime == TENPM || mTime == MIDNIGHT)
        return true;
    
    return false;
}

double MovieTicket::getCost()
{
    double cost = 0.0;
    
    if (mType == CHILD)
        cost = cost + 3.50;
    
    if (mType == ADULT)
        cost = cost + 7.50;
    
    if (mType == SENIOR)
        cost = cost + 4.50;
    
    if (isMatineeTicket()==true)
        cost = cost - 2.00;
    
    if (mKind==BLOCKBUSTER)
        cost = cost +1.00;
    
    if (mKind==GRANDOPENING)
        cost = cost +2.00;
    
    if (mKind==BOMB)
        cost = cost -1.00;
    
    return cost;
}
