//header gaurds
#ifndef PROG1_H
#define PROG1_H

//system header files
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

//const integers
const int LOW = 1; // use for RNG for lowest number
const int HIGH = 1000; // use for RNG for highest possible number
const int VEC_SIZE = 250; // int use for the size of vector
const int SEED = 1; //use for srand()
const int NO_ITEMS = 12; // numbers to print out in a single line
const int ITEM_W = 5;// to use for spaceing between numbers

/********************************************************************
	              		genRndNums
	this function accepts an int vector as its only argument.
	it generates VEC_SIZE random numbers and stores them in
	the vector privided. It also generates random numbers
	between 1(LOW) and 1000(HIGH).
********************************************************************/
void genRndNums(vector <int>& v)
{
	srand(SEED);
	//for loop to  genereta and set the random numbers into the vector.
	for(int i = 1; i <= VEC_SIZE; i++)
	{
		v.push_back(rand()%(HIGH-LOW+1)+LOW);
	}
}

/***********************************************************************
				printVec
	this function takes in a vector of type integer. it prints out
	the contents of the vector. It prints them out organized in 12 lines
************************************************************************/
void printVec(const vector <int>& v)
{
	//for loop to access the vector in print out its content.
	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << setw(5) << v[i] <<setw(5);

		// condition statement to print out a new line every 12 number.
		if(i % 12 == 0)
			cout << endl;
	}
}


#endif
