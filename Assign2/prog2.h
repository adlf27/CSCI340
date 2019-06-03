//header guards
#ifndef PROG2_H
#define PROG2_H
// C++ system libraries
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>

using namespace std;

//constant integers used thru out the program
const int ARR_SIZE = 200;
const int TEST_ARR_SIZE = 100;
const int SEED1 = 1;
const int SEED2 = 3;
const int LOW = 1;
const int HIGH = 1000;

	//prototype for fucntion vectors
	void Vectors(vector <int>&, vector <int>&, int, int);
	//protype for linear search function
	bool linearSearch(const vector <int>&, int);
	//prototype foe binary search function
	bool binarySearch(const vector <int>&, int);
	//prototype for a generinc search function
	int search(const vector <int>&, const vector <int>&, bool(*p)
	  (const vector <int>&, int));
	//prototype of funciton to sort vectors
	void sortVector(vector <int>&);
	//prototype to print out vectors
	void printVector(const vector <int>&);
	//prototype to the function to print statistics
	void printStat(int, int);

#endif
