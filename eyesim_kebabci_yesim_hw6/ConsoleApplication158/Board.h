#ifndef BOARD_H
#define BOARD_H

#include<string>
using namespace std;

class Board
{
	public:
		Board();
		
		bool MakeAHit(int row, int col);
		bool checkIfPlayerWon(int p_id) const; 
		bool putShip(int p_id, int s_ip, int row_s, int col_s, int row_e, int col_e);
		void displayBoard()const;
	
	private:
		int myBoard[6][6];
		
};
#endif