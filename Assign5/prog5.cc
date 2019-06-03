/*****************************************************
Name: Luis Agiunaga
Z-ID: z1811673
Assignment 5
Date: 10/10/2017
*****************************************************/
#include "/home/cs340/progs/17f/p5/prog5.h"

/*************************************************
                   init_vals
this function gets the input values for the user
and initializes the data members in the
struct.
**************************************************/
void init_vals(vector <string>& v, inargs &in)
{
	unsigned N, M, K;
	cin >> N >> M >> K; //gets input from  user
	in = {N, M, K}; //initialise the struct members

	cout << "Number of people? " << in.N << endl;
	cout << "Index for elimination? " << in.M << endl;
	cout << "Index for printing? " << in.K << endl;

	v.resize(in.N); //resize the vector with the N value enter
	generate(v.begin(), v.end(), SEQ(in.N)); //fill nametags in vector
}

/*************************************************************
                          print_vector
this function prints out the content in the vector. it takes in
a const reference to the vector and a const reference to the
int cnt. 
*************************************************************/
void print_vector(const vector <string>& v, const unsigned& cnt)
{
	int lineA = 0, lineB = 0;

	vector <string>::const_iterator it;//iterator to go thru the vector

	//condition statement so the initial group is only printed once
	if(cnt == 0)
	{
		cout << "\nInitial group of people"<< endl;
		cout << "------------------------" << endl;

		//for loop so the iterator goes thru the vector 
		for(it = v.begin(); it != v.end(); it++)
		{
			cout << *it << " ";
			lineA++;
			if( lineA % NO_ITEMS == 0)
				cout << endl;
		}
	}
	else
	{
		cout << "\nAfter eliminating "<< cnt << "th person" << endl;
		cout << "--------------------------------------" << endl;

		//for loop to  print vector
		for (it = v.begin(); it != v.end(); it++)
		{
			cout << *it << " ";
			lineB++;
			if( lineB % NO_ITEMS == 0)
				cout << endl;
		}
	}

	cout << endl;
}
//main driver program for assignment5
int main()
{
	//declares a struct object
	inargs in;

	//creates a vector of string
	vector <string> v;

	//calls the init_vals to initalize the struct members
	init_vals(v,in);

	unsigned cnt = 0;

	//calls the print function
	print_vector(v, cnt);

	//for loop to loop thru the vector to erase the Mth values
	for(unsigned i = 0;i <= v.size();)
	{
		i=(i + in.M - 1) % v.size();
		v.erase(v.begin()+i);
		cnt++;

		//print out only K amount of times
		if(cnt % in.K == 0)
			print_vector(v, cnt);

		//breaks the loop and prints out the remainder value
		else if(cnt == in.N-1)
		{
			print_vector(v, cnt);
			break;
		}
	}

	return 0;
}
