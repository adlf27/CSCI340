#ifndef PROG3_H //header guards
#define PROG3_H

#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

/****************************************************************************
                               sieve
	This function takes in a reference to a set and an interger.
it returns nothing. this function initialize the set with numbers up to
the upper limint provided as a parameter. then it uses a while loop to remove
any number that is not a prime number.
*****************************************************************************/

void sieve(set <int>& s, int n)
{
	//variables to hold the current postion
	// and to hold the value to be remove
	int curr_num, remove_num;
	//for loop to fill the set with numbers up to the int "n".
	for (int i = 2; i <= n; i++)
		s.insert(i);

	//iterator to go thru the set
	set <int>::iterator it = s.begin();
	//first while loop to go thru the set until the end
	while (it != s.end())
	{
		//sets the curr_num to the current value
		//then the iterator takes value with increment
		curr_num = *it++;
		remove_num = curr_num + curr_num;

		//second while to just go up to the n=1000
		while(remove_num <= n)
		{
			//erases the values in remove_num from the set
			s.erase(remove_num);
			remove_num += curr_num;

		}
	}
}
/******************************************************************************
                              print_Primes
	this function takes in a const reference of a set and retruns nothing.
 the function prints out tne content in the set with a for loop and iterator
to go thru the set elements.
*******************************************************************************/

void print_Primes(const set <int>& s)
{
	set <int>::const_iterator it;
	//variable to keep count in the for loop
	int count = 0;
	//for loop to access all the values in the set
	for(it = s.begin(); it != s.end(); it++)
	{
		cout << setw(4) <<*it;
		count++;
		//condition statement to print an endline every 16 row
		if( count % 16 == 0)
			cout << endl;

	}
	cout << endl;

}

#endif
