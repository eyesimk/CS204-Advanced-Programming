#include <iostream>
#include <string>
#include "DynIntStack.h"
#include <fstream>
#include <sstream>

using namespace std;

void deletestack(DynIntStack & Stack, int number) // function to delete the stack
{
	while (! Stack.isEmpty() )
	{
		Stack.pop(number);

	}
}
int spacecounter ( char ch, int spacenum, istringstream & input)
{
	
	while (input.get(ch))
		{
			if ( ch == ' ' )
			{
				spacenum += 1;
			}

			else

				return spacenum;
				break;
	}
}

void projectfinish(DynIntStack & Stack, int number) // function to finish project
{
	deletestack(Stack,number);
	cout << "Stack emptied and program ending. " << endl;

}

bool keyword_found(string word)
{
	if ( word == "if" || word== "else" || word == "elif" || word == "for" || word == "while")
	{
		 return true;
	}

	return false;
}

int main(){

	
	
	DynIntStack stack; 
	string filename,line;
	int preline; 
	fstream text;
	bool outer = false;
	cout << "Please enter the file name that is going to be analyzed.  "<< endl;
	cin >> filename;
	
	text.open(filename); 

	while (text.fail()) 
	{
		cout<< "Unable to open file please enter a different file name" << filename  <<  endl;
		cin >> filename;
		text.open(filename);
	}

	cout << "Starting file analysis... "  << endl;
	stack.push(0);
	cout << "Initial indentation level is pushed to the stack as 0. " << endl << endl;
	


	char ch; 
	string word, word2, word3, word4; 

	int spacenum = 0;
	int linenum = 1; 
	bool keyfollow = false; 
	int current_num = 0;

	while (getline(text,line)) 
	{ 
		
		cout << "Line number: " << linenum << endl;
		
		cout << "Line: " << line << endl;

		istringstream input1(line); //for the characters
		istringstream input2(line); //for the words

		while (input1.get(ch)) //counting the spaces before the words
		{
			if ( ' ' == ch )
			{
				spacenum += 1;
			}
			else
			{
				
			cout << spacenum << " number of spaces observed before the start of the line. " <<  endl;
			current_num = spacenum ;
			spacenum = 0;
			break;
			}
		}

		stack.pop(preline); //popping the first element of stack called "preline"
		

		if (linenum == 1 ) //to check that first line's Indentation == 0
		{
			if (current_num > 0)
			{
				cout << "Current Level = " << current_num << " This Line = " << preline << endl;
				cout << "Incorrect file structure. " << endl;
				cout << "Current line cannot be greater than the Current indentation level. " << endl;
				cout << "Stopping file analysis... " << endl << endl;
				projectfinish(stack,preline);
				return 0;
			}
		}
			linenum += 1;

			

		while (input2 >> word) 
		{

		if ( keyword_found(word) == false) //if it is not a "keyword"
		{

			if ( keyfollow == false) //if it is not a following line of a "keyword"
			{
				while(current_num < preline)
				{
					cout << "Current Level = " << preline << " This Line = " << current_num << endl;
					cout << "Current line is smaller than Current indentation level; checking if line belongs to outer indentation. " << endl;
					stack.pop(preline);
					outer = true;
					
				}

				

				if (current_num == preline)
				{
					
					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					if (outer == true)
						cout << "Line belongs to outer block. " << endl;
					else
					cout << "Line belongs to current block. " << endl << endl;
					stack.push(current_num);
					keyfollow =  false;
					outer =false;
				}

				else
				{
					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					cout << "Incorrect file structure" << endl;
					if (outer == true)
						cout << "An indentation level same as the Current line is not found in outer blocks. " << endl;
					cout << "Stopping file analysis... " << endl << endl;
					projectfinish(stack,preline);
					return 0;
				}

			}

			if (keyfollow == true) //if it is a following line of a "keyword"
			{
				cout << "This line proceeds a keyword containing line. " << endl;

				if (current_num <= preline)
				{
					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					cout << "Incorrect file structure" << endl;
					cout << "Current line must be greater than the Current indentation level. " << endl;
					cout << "Stopping file analysis... " << endl << endl;
					projectfinish(stack,preline);
					return 0;
				}

				else
				{
				
				cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
				cout << "Line correct. Depth " << current_num << " added to the stack. " << endl << endl;
				stack.push(current_num);
				keyfollow = false;
				}

			}

		}

		else if (  keyword_found(word) == true) //if it is not a "keyword"
		{
			if ( keyfollow == false)
			{
				
					while(current_num < preline)
				{
					cout << "Current Level = " << preline << " This Level = " << current_num << endl;
					cout << "Current line is smaller than Current indentation level; checking if line belongs to outer indentation. " << endl;
					
					stack.pop(preline);
					outer = true;
					
				}
					stack.push(preline);
					

				if (current_num >= preline)
				{

					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					if (outer == true)
					cout << "Line belongs to outer block. " << endl ;
					else
					cout << "Line belongs to current block. " << endl  ;
					cout << "Keyword " << word << " found on this line." << endl; 
					stack.push(current_num);
					keyfollow = true;
					outer = false;
					
					cout << endl;
 
				}



				else
				{
					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					cout << "Incorrect file structure" << endl;
					if (outer == true)
						cout << "An indentation level same as the Current line is not found in outer blocks. " << endl;
					cout << "Stopping file analysis... " << endl << endl;
					projectfinish(stack,preline);
					return 0;
				}

			}
				
				else if ( keyfollow == true)
				{
					cout << "This line proceeds a keyword containing line. " << endl;

					if (current_num <= preline)
					{
					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					cout << "Incorrect file structure" << endl;
					cout << "Current line must be greater than the Current indentation level. " << endl;
					cout << "Stopping file analysis... " << endl << endl;
					projectfinish(stack,preline);
					return 0;

			}
					

					else
					{
					cout << "Current Level = " << preline << " This Line = " << current_num  << endl;
					stack.push(preline);
					cout << "Line correct. Depth " << current_num << " added to the stack. " << endl ;
					cout << "Keyword " << word << " found on this line." << endl;
					stack.push(current_num);
					keyfollow = true;
					cout << endl;
					}

			}
		}
		break;
		}
		}

		cout << endl;
		cout << "Finished file analysis. File structure is correct! " << endl;
		deletestack(stack,preline);
		cout << "Stack emptied and program ending. " << endl;

	return 0;
	}
	
