#include <iostream>
    #include <string>
    #include <cassert>

        #include "MovieTicket.h"
        #include "BoxOffice.h"

    using namespace std;

    int main()
    {
            // sample test code
            
        
            BoxOffice b( "1900 Pico Boulevard", "Titanic" );
            assert( b.getAddress() == "1900 Pico Boulevard" );
            assert( b.whatsPlaying() == "Titanic" );
            assert( b.getWeekendTickets( ) == 0 );
            assert( b.getWeekdayTickets( ) == 0 );
            assert( b.getMatineeTickets( ) == 0 );
            assert( b.getEveningTickets( ) == 0 );

            // use care when working with assert on doubles
            assert( std::to_string( b.getRevenue() ) == "0.000000" );


            MovieTicket t( "The Lake House", MovieTicket::Day::MONDAY, MovieTicket::Time::TWOPM, MovieTicket::Kind::BOMB, MovieTicket::Type::ADULT );

            assert( t.getMovie() == "The Lake House" );
            assert( t.getDay() == MovieTicket::Day::MONDAY );
            assert( t.getTime( ) ==  MovieTicket::Time::TWOPM  );
            assert( t.getKind( ) ==  MovieTicket::Kind::BOMB );
            assert( t.getType( ) ==  MovieTicket::Type::ADULT );
            assert( t.isWeekendTicket( ) == false );
            assert( t.isWeekdayTicket() == true );
            assert( t.isMatineeTicket( ) == true );
            assert( t.isEveningTicket() == false );

            // use care when working with assert on doubles
            // since the BoxOffice b did not create the ticket...
            assert( std::to_string( b.getRevenue() ) == "0.000000" );




             try
             {
                        MovieTicket m = b.buyTicket( "The Wizard of Oz", MovieTicket::Day::MONDAY,
                                                     MovieTicket::Time::NOON, MovieTicket::Kind::REGULAR,
                                                     MovieTicket::Type::ADULT );
                        assert( false );  // we are expecting the buyTicket to fail....
             }
             catch( std::logic_error )
             {
                        assert( true );
             }

             try
             {
                        MovieTicket m = b.buyTicket( "Titanic", MovieTicket::Day::MONDAY,
                                                     MovieTicket::Time::NOON, MovieTicket::Kind::REGULAR,
                                                     MovieTicket::Type::ADULT );
                        assert( true ); // we are expecting the buyTicket to succeed....
             }
             catch( std::logic_error )
             {
                        assert( false );
             }

             cout << "all tests passed!" << endl;
             return( 0 );
}
