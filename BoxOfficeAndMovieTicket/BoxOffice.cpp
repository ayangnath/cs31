//
//  BoxOffice.cpp
//  Project 5
//
//  Created by Ayan Nath on 7/26/22.
//

#include <stdio.h>
#include "BoxOffice.h"
#include <iostream>
#include <string>
using namespace std;

BoxOffice::BoxOffice()
{
    
}

BoxOffice::BoxOffice(string address, string whatsPlaying)
{
    mAddress=address;
    mMovie=whatsPlaying;
}

MovieTicket BoxOffice::buyTicket(string movie, MovieTicket::Day day, MovieTicket::Time time, MovieTicket::Kind kind, MovieTicket::Type type)
{
//    return MovieTicket(mMovie, MovieTicket::MONDAY, MovieTicket::NOON,MovieTicket::REGULAR, MovieTicket::CHILD); //not correct
    if (movie != mMovie)
    {
        throw std::logic_error("The requested movie string value must match the BoxOffice's mMovie value!");
        
        
        //        logic_error le("The requested movie string value must match the BoxOffice's mMovie value!");

        //        throw (le);
    }
    
    MovieTicket current(movie, day, time, kind, type);
    
    mTicketCount++;
    mEarnedRevenue = mEarnedRevenue + current.getCost();
    
    if (current.isWeekendTicket()==true)
        mWeekendTickets++;
    
    if (current.isWeekdayTicket()==true)
        mWeekdayTickets++;
    
    if (current.isMatineeTicket()==true)
        mMatineeTickets++;
    
    if (current.isEveningTicket()==true)
        mEveningTickets++;
    
    return current;
}

string BoxOffice::getAddress()
{
    return mAddress;
}

string BoxOffice::whatsPlaying()
{
    return mMovie;
}

int BoxOffice::getWeekendTickets()
{
    return mWeekendTickets;
}

int BoxOffice::getWeekdayTickets()
{
    return mWeekdayTickets;
}

int BoxOffice::getMatineeTickets()
{
    return mMatineeTickets;
}

int BoxOffice::getEveningTickets()
{
    return mEveningTickets;
}

double BoxOffice::getRevenue()
{
    return mEarnedRevenue;
}

