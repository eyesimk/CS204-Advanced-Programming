//ece yesim kebabci
#include "Header.h"
#include <iostream>

using namespace std;

Matrix::Matrix() //default constructor
{
  rows = 0;
  cols = 0;
  data = NULL;
}

Matrix::Matrix(int r, int c, int init)
{   
	if ( r < 0 || c < 0)
	{
		r = 0;
		c = 0;
	}
	
	 rows=r;
	 cols=c;
     data = new int* [r];

	for (int i = 0; i<rows; i++) 
	{
		data[i] = new int[cols];

		for (int a  = 0; a < cols ; a++){
			data[i][a] = init;
		}

	}
	
}




int ** Matrix::createClone() const {

	int ** cdata = new int*[rows];

	for (int i= 0; i < rows; i++)
	{
		cdata[i] = new int[cols];
		
			for (int a = 0; a < cols; a++)
				cdata[i][a] = data[i][a];
	}
	
	return cdata;
}


Matrix::Matrix (const Matrix & copy)
{
	data = copy.createClone();
	rows = copy.rows;
	cols = copy.cols;
}


 Matrix ::~Matrix() {
    for (int i = 0; i < rows; i++) {

        delete[] data[i];
    }
    delete[] data;
}


void Matrix::print() const
{
	for (int i = 0; i < rows; i++) 
	{ 
  		for (int j= 0 ; j< cols ; j++) 
         cout << data[i][j] << " "; 
		cout << endl; 
	} 
}

int Matrix::getRowNumber(){

	return rows;
}

int Matrix::getColumnNumber(){

	return cols;
}


void Matrix::setElementAt(int x, int y, int s){

	data[x][y] = s;

}

int Matrix::getElementAt(int i, int j)
{
    return data[i][j];
}

void Matrix::deleteMatrix ()
{
	for (int i = 0; i < rows; i++) {

        delete[] data[i];
    }
    delete[] data;

	rows = 0;
	cols = 0;
	data = NULL;

}

const Matrix & Matrix::operator = (const Matrix & rhs){

	if (this != &rhs)
	{
		deleteMatrix();
		data = rhs.createClone();
		rows = rhs.rows;
		cols = rhs.cols;

	}
	return *this;
}
bool Matrix::Equals(const Matrix & m) const
{
	if ( (rows == m.rows) && (cols == m.cols))
	{
		for (int i= 0; i < rows; i++)
		{
			for (int a = 0; a < cols; a++){

				if(m.data[i][a] == data[i][a])
				{
					return true;
					
				}
				
				
	}

	}


}
	return false;
}

bool operator ==  (const Matrix & lhs, const Matrix& rhs){

	return (lhs.Equals(rhs));

}

const Matrix & Matrix::operator+= (const Matrix & m)
{
   for (int i= 0; i < rows; i++)
		{
			for (int a = 0; a < cols; a++){

				data[i][a] += m.data[i][a];
			}
				
   }
    return *this;				
}



const Matrix & Matrix::operator-= (const Matrix & m)
{
   for (int i= 0; i < rows; i++)
		{
			for (int a = 0; a < cols; a++){

				data[i][a] -= m.data[i][a];
			}
				
   }
    return *this;				
}

Matrix operator+ (const Matrix & lhs, const Matrix & rhs)
{
    Matrix solution(lhs);	
    solution += rhs;		
    return solution;
}

Matrix operator- (const Matrix & lhs, const Matrix & rhs)
{
    Matrix solution(lhs);	
    solution -= rhs;		
    return solution;
}

const Matrix & Matrix:: operator! ()
{
	Matrix nmatrix(cols,rows,0);


	for (int i= 0; i < rows; i++)
		{
			for (int a = 0; a < cols; a++){
				
				  nmatrix.data[a][i] =data[i][a] ;
			}
   }
	*this = nmatrix;

	return *this;
}

