#include "/home/cs340/progs/17f/p8/prog8.h"

int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}
/**************************************************************
This function gets the contect for the files and puts them into
the vector. takes in two arguments. reference to the vector and
a pointer to the path of the file
***************************************************************/
template<class T>void get_list(vector<T>& v, const char* path)
{
  v.clear();
  //decleara ifstream objecto to open file
  ifstream myFile;
  myFile.open(path);
  //make sure that the file opens if not exit
  if(myFile.fail())
  {
    cout << "Error opening File." << endl;
    return;
  }
  else
  {
    //tempt variable to store the data
    T tmp;
    while(!myFile.eof())
    {
      myFile >> tmp; //store data into tmp
      v.push_back(tmp);  //store the data in tmp into the vector
    }
  }
  //closes the file
  myFile.close();
}
/***************************************************************
this fucntion uses the make_heap and sort_heap to construct a heap
with the values in the vector.
****************************************************************/
template<class T, class P>void construct_heap(vector<T>& v, P pred)
{
  make_heap(v.begin(), v.end(), pred);
  sort_heap(v.begin(), v.end(), pred);
}

//constructor for the print list class
template<class T>print_list<T>::print_list(const unsigned& s, const unsigned& w,
const unsigned& l, const unsigned& c):sz(s), wid(w), len(l), cnt(c)
{
}

/*************************************************************
this function print out the content in the heap with the
corresping output.
**************************************************************/
template<class T>void print_list<T>::operator()(const T& x)
{
  cout.width(wid); cout.precision(2);
  cout << fixed << showpoint;
  //if counter eqauls the lenght of iteam in one line
  //print out endline
  if( cnt % len == 0)
    cout << endl;
  //print out the data in x
  cout << x << " ";
  cnt++;
  //if counter equal the size of the heap
  //print out endline
  if(cnt == sz)
    cout << endl << endl;

}
