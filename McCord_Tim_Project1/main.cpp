#include <iostream>
#include <ctime>
#include "sort.h"
#include <algorithm>

#define SIZE 100000

using namespace std;

/*These first two functions are simply my utiltities for printing all or part of an array
  which could have been included in the sort.h file.  They were placed in main.cpp
  to keep my version of sort.h close to what I expected yours to look like. 
*/ 
// forward declarations 
void print( const vector<int> & v ) ;
void print( int arr[], int size ) ;


int main( )
{
  // it's a good idea to check this when changing compilers
  cout << "Default clock ticks per second: " << CLOCKS_PER_SEC << endl ; 
    
	srand(time(NULL));   // seed the random number generator
  long start_t, end_t ;  // basic time in ms. (assuming 1000 CLOCKS_PER_SEC)  

  cout << "RAND_MAX is " << RAND_MAX << endl ;
	int arr[SIZE]; 
  vector<int> v ;

  // initialize array
	for( int i = 0; i < SIZE; i++ )
      arr[i] = rand() ;

  // initialize the vector
  for( int i = 0; i < SIZE; i++ )
    v.push_back( rand() ) ; 

	//cout << "Array before sorting: " << endl;
  //print(arr, SIZE) ;

  start_t = clock() ;
  sort(arr, SIZE) ;
  end_t = clock() ;

  cout << "Elapsed time for sorting primitive array of " << SIZE << " elements: " << end_t - start_t << endl ; 

  //cout << "Array after sorting: " << endl;
  //print(arr, SIZE) ; 


	//cout << "Vector before sorting: " << endl;
  //print(v) ; 
  start_t = clock() ;
	sort(v) ;
  end_t = clock() ;

  cout << "Elapsed time for sorting vector of " << SIZE << " elements: " << end_t - start_t << endl ; 
  //cout << "Vector after sorting: " << endl;
  //print(v) ;

  // 502 only

  
  cout << endl << "502 Only" << endl ;
  cout << "=================================" << endl ;
  // reinitialize array
  for( int i = 0; i < SIZE; i++ )
    arr[i] = rand() ;
  start_t = clock() ;
  sort(arr, arr+SIZE) ;
  end_t = clock() ;
  cout << "Elapsed time for built-in sort with array of " << SIZE << " elements: " << end_t - start_t << endl ;

  // clear and reinitialize vector
  v.clear() ;
  for( int i = 0; i < SIZE; i++ )
    v.push_back( rand() ) ; 
  start_t = clock() ;
  sort(v.begin(), v.end() ) ;
  end_t = clock() ;
  cout << "Elapsed time for built-in sort with vector of " << SIZE << " elements: " << end_t - start_t << endl ;


	cout << endl ; 
	system("PAUSE") ;
  return 0 ;
}


// I did not write an isSorted function for this one, but I could have used in place of 
//   printing excerpts. 

void print( const vector<int> & v ) 
{
  // if the vector is larger than a certain size, print only the first
  // few elements and the last few, verifying that it is sorted under 
  // most circumstances.
  int size = v.size() ; 
  if ( size > 100 ) {
    cout << v[0] << ", " << v[1] << ", " << v[2] << " ... " ;
    cout << v[size-3] << ", " << v[size-2] << ", " << v[size-1] << endl ;
  }
  else { 
    for ( auto item : v )
		  cout << item << "\t" ;
	  cout << endl;  }
}

void print( int arr[], int size )
{ 
  // if the array is larger than a certain size, print only the first
  // few elements and the last few, verifying that it is sorted under 
  // most circumstances
  if ( size > 100 ) {
    cout << arr[0] << ", " << arr[1] << ", " << arr[2] << " ... " ;
    cout << arr[size-3] << ", " << arr[size-2] << ", " << arr[size-1] << endl ;
  }
  else { 
    for( int i = 0; i < size; i++ )
      cout << arr[i] << "\t" ;
	  cout << endl;
 }
}

/* 
All times are in milliseconds using Visual Studio 2012 in Release mode.  
My implementation used selection sort to intentionally maximize the sheer number
of operations, but notice that the Java built-in sort (CSC 502 only) uses a much more efficient algorithm, guaranteed
to be O n log2 n.  
I have a #define in my code to easily switch to QuickSort, which I did in a 4th set of trial runs with 100000 elements. 
The machine is a 4-core i5 @ 3.10 GHz, though only the built-in sorts could potentially take advantage 
of multiple cores.   


Default clock ticks per second: 1000    ( = ms) 
RAND_MAX is 32767


1)  Three trials with SIZE = 1000 


Elapsed time for sorting primitive array of 1000 elements: 0
Elapsed time for sorting vector of 1000 elements: 0

502 Only
=================================
Elapsed time for built-in sort with array of 1000 elements: 0
Elapsed time for built-in sort with vector of 1000 elements: 0


Elapsed time for sorting primitive array of 1000 elements: 0
Elapsed time for sorting vector of 1000 elements: 1

502 Only
=================================
Elapsed time for built-in sort with array of 1000 elements: 0
Elapsed time for built-in sort with vector of 1000 elements: 0



Elapsed time for sorting primitive array of 1000 elements: 1
Elapsed time for sorting vector of 1000 elements: 0

502 Only
=================================
Elapsed time for built-in sort with array of 1000 elements: 0
Elapsed time for built-in sort with vector of 1000 elements: 0



2)  Three trials with SIZE = 10000 


Elapsed time for sorting primitive array of 10000 elements: 33
Elapsed time for sorting vector of 10000 elements: 34

502 Only
=================================
Elapsed time for built-in sort with array of 10000 elements: 1
Elapsed time for built-in sort with vector of 10000 elements: 1



Elapsed time for sorting primitive array of 10000 elements: 32
Elapsed time for sorting vector of 10000 elements: 34

502 Only
=================================
Elapsed time for built-in sort with array of 10000 elements: 1
Elapsed time for built-in sort with vector of 10000 elements: 0



Elapsed time for sorting primitive array of 10000 elements: 32
Elapsed time for sorting vector of 10000 elements: 35

502 Only
=================================
Elapsed time for built-in sort with array of 10000 elements: 1
Elapsed time for built-in sort with vector of 10000 elements: 1




3)  Three trials with SIZE = 100000 

Elapsed time for sorting primitive array of 100000 elements: 3106
Elapsed time for sorting vector of 100000 elements: 3391

502 Only
=================================
Elapsed time for built-in sort with array of 100000 elements: 8
Elapsed time for built-in sort with vector of 100000 elements: 8




Elapsed time for sorting primitive array of 100000 elements: 3110
Elapsed time for sorting vector of 100000 elements: 3389

502 Only
=================================
Elapsed time for built-in sort with array of 100000 elements: 7
Elapsed time for built-in sort with vector of 100000 elements: 7




Elapsed time for sorting primitive array of 100000 elements: 3120
Elapsed time for sorting vector of 100000 elements: 3390

502 Only
=================================
Elapsed time for built-in sort with array of 100000 elements: 7
Elapsed time for built-in sort with vector of 100000 elements: 7




4)  Extra trials with QuickSort as the algorithm to see how it compares to the built-in sorts


Elapsed time for sorting primitive array of 100000 elements: 13
Elapsed time for sorting vector of 100000 elements: 11

502 Only
=================================
Elapsed time for built-in sort with array of 100000 elements: 8
Elapsed time for built-in sort with vector of 100000 elements: 8



Elapsed time for sorting primitive array of 100000 elements: 6
Elapsed time for sorting vector of 100000 elements: 11

502 Only
=================================
Elapsed time for built-in sort with array of 100000 elements: 7
Elapsed time for built-in sort with vector of 100000 elements: 7




Elapsed time for sorting primitive array of 100000 elements: 6
Elapsed time for sorting vector of 100000 elements: 12

502 Only
=================================
Elapsed time for built-in sort with array of 100000 elements: 8
Elapsed time for built-in sort with vector of 100000 elements: 7

*/