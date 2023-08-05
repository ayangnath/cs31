#include <iostream>
    #include <string>
    #include <cassert>
    #include "Wordle.h"
    #include "Score.h"
    #include "Move.h"
    #include "Board.h"
    #include "Piece.h"

    int main()
    {
           using namespace std;
           using namespace cs31;

           // test code
           Piece p;
           assert( p.getLetter() == NOTVALID );
           p = Piece( "A" );
           assert( p.getLetter() == A );
           assert( p.getLetterAsString() == "A" );

           Move m;
           p = m.getPiece( 0 );
           assert( p.getLetter() == NOTVALID );
           m.setPieces( "hello" );
           p = m.getPiece( 2 );
           assert( p.getLetter() == L );
           m.setPiece( 2, 'z' );
           p = m.getPiece( 2 );
           assert( p.getLetter() == Z );

           Score s;
           assert( s.isExactMatch()  == false );
           assert( s.getAnswer( 2 ) == WRONG );
           m.setPieces( "hello" );
           Move theAnswer;
           theAnswer.setPieces( "stank" );
           s = Score( m, theAnswer );
           assert( s.isExactMatch() == false );
           assert( s.to_string() == "_____" );
           theAnswer.setPieces( "hello" );
           s = Score( m, theAnswer );
           assert( s.isExactMatch() == true );
           assert( s.to_string() == "RRRRR" );

           Board b;
           assert( b.getCurrentRound() == 0 );
           m.setPieces( "hello" );
           theAnswer.setPieces( "logic" );
           s = Score( m, theAnswer );
           b.endRound( m, s );
           assert( b.getCurrentRound() == 1 );
           assert( b.getMoveForRound( 0 ).to_string() == "HELLO" );
           assert( b.getScoreForRound( 0 ).to_string() == "__M_M" );

           Wordle game( "apple" );
           assert( game.answer() == "APPLE" );
           assert( game.gameIsOver() == false );
           m = game.play( "taboo" );
           s = game.endRound( m );
           assert( s.to_string() == "_M___" );

           cout << "all tests passed!" << endl;
           return( 0 );
       }  
