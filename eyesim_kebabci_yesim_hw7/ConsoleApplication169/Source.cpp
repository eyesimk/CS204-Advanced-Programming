//ece yesim kebabci

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <random>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include<iomanip>
using namespace std;

mutex fMutex;
int sharedSum;
int indexCounter;
int iterations;

int random_range(const int & min, const int & max) 
{
    static mt19937 generator(time(0));
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}

void Addition (int* newarray, int id, int x,int y){

	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	struct tm *ptm = new struct tm; 
	localtime_s(ptm, &tt); 
	
	while (indexCounter < iterations)
 {
	bool isLocked;
    isLocked = fMutex.try_lock();
    if (isLocked)
    {
	
	this_thread::sleep_for(chrono::seconds(random_range(x,y)));
	sharedSum += newarray[indexCounter];
	tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	localtime_s(ptm, &tt);

	cout << "Thread " << id << " added number index " << indexCounter << " to the total sum at " << put_time(ptm,"%X") << endl;
	cout << "Current Sum: " << sharedSum << endl;
	indexCounter ++;
	fMutex.unlock();
	}
 }
}



int main()
{
string filename,line;
int mint,maxt,amount;
fstream file;

cout << "Please enter the file name. " << endl;
cin >> filename;

file.open(filename);
cout <<"Please enter the wait range of threads."  << endl;
cin >> mint >>maxt;

int * newarray;

int linennum = 0;
int size;
thread mythreads[5];
int x = 0;

while (getline(file,line))
{
	istringstream input1(line);

	while (input1 >> amount)
	{
		linennum += 1;
		
		if (linennum == 1)
		{
			size = amount;
			newarray = new int[size];
		}

		else
		{
			newarray[x] = amount;
			x++;
		}
	}
}



  time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  struct tm * ptm = new struct tm; 
  localtime_s(ptm, &tt); 

  cout << "Starting reading the array at " << put_time(ptm,"%X")<<endl; 
  cout << "Array stored in the memory. Starting the summation at " << put_time(ptm,"%X") << endl << endl;

  iterations = size;
  

  for (int i=0; i < 5; i++)
  { 
	mythreads[i] = thread(&Addition,newarray,i+1,mint,maxt);
  }
  
    for (int i=0; i < 5; i++)
  {
      mythreads[i].join();
  }
	cout << endl;
	
	tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	localtime_s(ptm, &tt);
	cout << "Adding finished at "  << put_time(ptm,"%X") << endl;
	cout << "Sum: " << sharedSum << endl;
 return 0;
}