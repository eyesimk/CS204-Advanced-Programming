//ece yesim kebabci

#ifndef matrix_class 
#define matrix_class


class Matrix {

	private: 
		int rows, cols;
		int ** data;

    public:
		Matrix(int r, int c, int init); //constructor
		Matrix(); // default construstor
		Matrix (const Matrix &); //deep copy
		~Matrix (); //destructor
		int getRowNumber();
		int getColumnNumber();
		int getElementAt(int x, int y);
		void setElementAt(int x, int y, int s);
		void print() const ;
		bool Equals(const Matrix & m) const;
		const Matrix & Matrix::operator+= (const Matrix & m);
		const Matrix & Matrix::operator = (const Matrix & rhs);
		const Matrix & Matrix::operator-= (const Matrix & m);
		const Matrix & Matrix::operator! ();
		

		void deleteMatrix();
		int ** createClone() const; //generates the clone of the matrix 
};

bool operator ==  (const Matrix & lhs, const Matrix & rhs);
Matrix operator+ (const Matrix & lhs, const Matrix & rhs);
Matrix operator- (const Matrix & lhs, const Matrix & rhs);


#endif