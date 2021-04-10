#include "Header.h"
#include "Board.h"
#include<iostream>


using namespace std;


bool Player::wins()
{

	return board.checkIfPlayerWon(this->player_id);

}

bool Player::guess(int row, int column){


	return board.MakeAHit(row,column);
}