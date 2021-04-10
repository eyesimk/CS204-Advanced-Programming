//eceyesimkebabci
#include "Board.h"
#include <iostream>
#include <iomanip> 

using namespace std;


//default constructor
Board::Board()
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			myBoard[i][j] = 0;
		}
	}
}

void Board::displayBoard()const
{
	cout << "Board: " << endl;
	cout << setw(9) << "P1" << setw(7) << "|" << setw(9) <<  "  P2" << endl;;
	for(int i=0; i<6; i++)
	{
		
		for(int j=0; j<6; j++)
		{
			if ( j == 3 )
				cout << setw(4) <<"  |" ;
			cout << setw(4) << myBoard[i][j] ;
		}
		
		cout << endl;
	}
	
}

bool Board:: putShip(int p_id, int s_id, int row_s, int col_s, int row_e, int col_e)
{
int first_coor = row_s + col_s;
		int last_coor = row_e + col_e ;
	
		if (p_id == 1)
		{
		
		
			if ( col_s > -1 && col_s < 3 && row_s > -1 && row_s < 6 && col_e < 3 && col_e > -1 && row_e > -1 && row_e < 6)
			{
				if (s_id == 1)
				{

			
					if (last_coor - first_coor == 1 || first_coor - last_coor == 1)
					{
						myBoard[row_s][col_s]=1;
						myBoard[row_e][col_e] =1;
						return true;
					}
					else 
						return false;
				}

				
			
				else if ( s_id == 2)
				{

				
					if ((last_coor - first_coor == 2 ) || (first_coor - last_coor == 2))
					{
						if (row_s == row_e){
							myBoard[row_s][col_s] = 1;
							myBoard[row_s][col_s +1] =1;
							myBoard[row_e][col_e] =1;
							return true;
						}
						else if (col_s == col_e){
							myBoard[row_s][col_s] = 1;
							myBoard[row_s +1][col_s] =1;
							myBoard[row_e][col_e]=1;
							return true;
						}
							
					}
				}
					else 
						return false;
			}
			return false;
		}

	else 
	{
		if ( col_s > 2 && col_s < 6 && row_s > -1 && row_s < 6 && col_e < 6 && col_e > 2 && row_e > -1 && row_e < 6)
		{
			if (s_id ==1)
			{
				
					if (last_coor - first_coor == 1 || first_coor - last_coor == 1)
					{
						myBoard[row_s][col_s]=1;
						myBoard[row_e][col_e] =1;
						return true;
					}

					else 
						return false;
				}

			else if ( s_id ==2)
			{

				
					if (last_coor - first_coor == 2 || first_coor - last_coor == 2)
					{
						if (row_s == row_e)
						{
							myBoard[row_s][col_s] = 1;
							myBoard[row_s][col_s +1] =1;
							myBoard[row_e][col_e] =1;
							return true;
						}

						else if (col_s == col_e)
						{
							myBoard[row_s][col_s] = 1;
							myBoard[row_s +1][col_s] =1;
							myBoard[row_e][col_e]=1;
							return true;
						}
							
					}	
			
			}
			
		}
			return false;

	}


}

bool Board::MakeAHit( int row, int column){
	if ( myBoard[row][column] ==1)
	{
		myBoard[row][column] = -1;
		return true;
	}
	else
		return false;

}

bool Board::checkIfPlayerWon(int player_id)const 
{
	bool check = true;
	if ( player_id == 1)
	{
			for(int i=0; i<6; i++)
		{
				for(int j=3; j<6; j++)
			{
				int value = myBoard[i][j];
					if (value == 1)
					{
					check =false;
					return check;
					}
					
			}
		}
		
	}
	else 
	{
				for(int i=0; i<6; i++)
			{
				for(int j=0; j<3; j++)
				{
					int value = myBoard[i][j];

					if (value == 1 )
					{
						check = false;
						return check;
					}
				}
			}
				
	}

	return check;
}