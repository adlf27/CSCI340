#include "prog3.h"

int main()
{
	int upper_Max; //variable to hold upper limit
	set <int> s;  //declares an empry set of integers

	cin >> upper_Max;  //gets the upper limi tfrom the user

	cout << "The upper limit is :" << upper_Max << endl;

	//call to the function to get rid of the non prime numbers.
	sieve(s, upper_Max);

	//calls the print function to print the elements in the set
	print_Primes(s);

	return 0;
}
