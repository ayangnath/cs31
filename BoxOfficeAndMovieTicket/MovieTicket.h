//
//  MovieTicket.h
//  Project 5
//
//  Created by Ayan Nath on 7/26/22.
//

#ifndef MovieTicket_h
#define MovieTicket_h
#include <string>
using namespace std;


class MovieTicket
{
public:
    
    enum Time
    {
        NOON,
        TWOPM,
        FOURPM,
        SIXPM,
        EIGHTPM,
        TENPM,
        MIDNIGHT
    };

    enum Day
    {
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY
    };

    enum Type
    {
        CHILD,
        ADULT,
        SENIOR
    };

    enum Kind
    {
        GRANDOPENING,
        BLOCKBUSTER,
        REGULAR,
        BOMB
    };
    
    //Constructors
    MovieTicket();

    MovieTicket(string movie, Day day, Time time, Kind kind, Type type);


    //accessors
    string getMovie();

    Day getDay();

    Time getTime();

    Kind getKind();

    Type getType();

    //other methods
    bool isWeekendTicket();
    bool isWeekdayTicket();
    bool isMatineeTicket();
    bool isEveningTicket();
    
    double getCost();
    
private:
    string mMovie;
    Day mDay;
    Time mTime;
    Kind mKind;
    Type mType;
};

#endif /* MovieTicket_h */
