//
//  Player.cpp
//  Pig
//
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // TODO: roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll( int amount )
    {
		//when we are actually rolling
		int this_result = 0;
		if (amount == 0) {
			mDie.roll();
			this_result = mDie.getValue();
		}
		//when we cheat
		else {
			this_result = amount;
		}
		if (this_result != 1) {
			mScore += this_result;
		}
		else {
			mScore = 0;
		}
		//return the result no matter what
        return( this_result );
    }
    
    // TODO: add the current score into the running total since the turn ended
    //       reset the current score to 0 for the next round of play
    void Player::endTurn()
    {
		mTotal += mScore;
		mScore = 0;
    }
    
    //FIN
	// TODO: return the current total
    int Player::getTotal( ) const
    {
        return( mTotal );
    }
    
    //FIN
	// TODO: return the current total
    int  Player::getScore( ) const
    {
        // stubbed out for now...
        return( mScore );
    }
    

}
