#include "prog1.h"

int main()
{
	vector <int> v;//decleares a vector named v

	genRndNums(v);//calls the function to generate the random #

	sort(v.begin(), v.end());// calls the member function of vector to sort

	printVec(v);//prints out the content of the vector
	return 0;
}
