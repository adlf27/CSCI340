#include "prog2.h"
/*****************************************************************************
                               Vectors
	This function fills the vectors provided in the argumnets
with random numbers using the RNG. it takes v1 and fills it  with 200 elements.
it fills v2 with 100 test elements.
******************************************************************************/
void Vectors(vector <int>& v1, vector <int>& v2, int s1, int s2)
{
	//for loops to fill vectors wiht ramdom numbers
	srand(s1);
	for (int i = 0; i <= ARR_SIZE;i++)
		v1[i] = rand()%(HIGH- LOW+1)+LOW;
	srand(s2);
	for(int i = 0; i <= TEST_ARR_SIZE; i++)
		v2[i] = rand() % (HIGH-LOW +1)+LOW;
}

/*****************************************************************************
                              printVectors
	this function prints out the elements in the vector in rows of 16.
it prints them out with 4 spaces in between eachother with(setw).
*****************************************************************************/
void printVector(const vector <int>& v)
{
	//forloops to acess the elements inside the vector and 
	//print the out with 4 spaces in between
	for(unsigned int i = 1; i <= v.size(); i++)
	{
		cout << setw(4) << v[i] ;
		if (i % 16 == 0)
			cout << endl;
	}
}

/********************************************************************
                           sortVector
	this function sorts the vectors in acending order. using the
the sort function in the stl
*********************************************************************/
void sortVector(vector <int>& v)
{
	//call to the sort function to sort the vectors
	sort(v.begin(), v.end()+1);
}

/****************************************************************************
                            linearSearch
	this function does a linear search using the find function from the
STL. it uses an iterator to go thru the vector to find the search element.
it returns true or false according to if the element was found.
****************************************************************************/
bool linearSearch(const vector <int>& v, int x)
{
	//declera a iterator to use to find the search
	//element with the function find().
	vector <int>::const_iterator it;
	it = find(v.begin(), v.end(), x);
	if (it != v.end())
		return true;

	return false;
}

/******************************************************************************
                                binarySearch
	this function uses the binary_search function in the STL to find the
element search. returns true or false according to if the elements was found
in the vector.
*******************************************************************************/
bool binarySearch(const vector <int>& v, int x)
{
	//call to a binary search fucntion to look for search element
	if(binary_search(v.begin(), v.end(), x))
		return true;

	return false;
}

/**********************************************************************************
                                search
	this function uses a pointer to a function to search thru the elements
either with the linear search or binary search. it returns an int which is the
amount of succesful elements found in the vector.
***********************************************************************************/
int search(const vector <int>& v1, const vector <int>& v2, bool(*p)
(const vector <int>&, int))
{
	//for loop to check if the serched element is found or not
	// then it updates the sucess variable accordandly
	int success;
	for (int i = 0; i <= TEST_ARR_SIZE; i++)
	{
		if( p(v1, v2[i]) == true)
			success++;
	}

	return success;
}

/**************************************************************************************
                               printStat
	this function prints out the succesful amount of element found in the vector.
it takes two parameters a succesful counter from the function search() and the vector
size.
****************************************************************************************/
void printStat(int totalSucCnt, int vectorSz)
{
	//prints out the  percent of successful found elements.
	//simple division between the vector size and the counter provided.
	float result = float(totalSucCnt) / float(vectorSz) * 100;
	cout << right << fixed << setprecision(2);
	cout << "\nPercent of Succesful Searches: " << result <<"%"<< endl;

}
