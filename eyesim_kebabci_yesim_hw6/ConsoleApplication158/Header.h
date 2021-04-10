#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include<string>
#include<iostream>
using namespace std;


class Player
{
	public:
		Player();
		
		Player::Player(Board &myboard,int id)
		: board(myboard), player_id(id)
		{ }

		bool guess( int row, int col);
		bool wins();

	private:
		Board &board;
		int player_id;
};
#endif