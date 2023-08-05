//
//  BoxOffice.h
//  Project 5
//
//  Created by Ayan Nath on 7/26/22.
//

#ifndef BoxOffice_h
#define BoxOffice_h
#include <string>
#include "MovieTicket.h"
using namespace std;

class BoxOffice
{
public:
    //Constructors
    BoxOffice();
    BoxOffice(string address, string whatsPlaying);
    
    //buyTicket method
    MovieTicket buyTicket(string movie, MovieTicket::Day day, MovieTicket::Time time, MovieTicket::Kind kind, MovieTicket::Type type);
    
    //accesors
    string getAddress();
    string whatsPlaying();
    int getWeekendTickets();
    int getWeekdayTickets();
    int getMatineeTickets();
    int getEveningTickets();
    double getRevenue();
    
private:
    string mAddress = "", mMovie = "";
    int mTicketCount = 0;
    int mMatineeTickets = 0, mEveningTickets =0;
    int mWeekdayTickets = 0, mWeekendTickets =0;
    double mEarnedRevenue = 0.0;
    
};


#endif /* BoxOffice_h */
