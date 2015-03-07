#include <vector>
#include <iostream>

using namespace std ;

class Test {

public:
  Test(int cap = 10) 
    : _capacity( cap )  // an experiment 
  {
    _arr = new int[_capacity] ; 
    // Question:  What do we do about _size ??? 
  }

  int size() const { 
    return _size ; }
  

private:
  int _capacity ; 
  int _size ;   // Is it a good idea just to let this default to 0 ?
  //int _capacity ;   // what happens if we change the order of these data members? 
  int *_arr ;   // pointer to an array of ints
} ;   // end of class Test


int main( ) {

  Test t1 ;
  cout << "Size of t1: " << t1.size() << endl << endl ; 

  // exploration of stack vs. heap allocation of arrays
  int capacity = 10 ;         // Note that capacity is a variable, not a constant
  //int arr1[capacity] ;      // cannot work as a stack-allocated array using a variable
  const int CAPACITY = 10 ;  // adding const to create a program constant is only a partial fix
  int arr2[CAPACITY] ;       // allocates const SIZE spaces of 4 bytes each
  
  // Aside: what does sizeof tell us with regard to arrays? 
  cout << "sizeof( arr2 ) = " << sizeof( arr2 ) << endl ;
  cout << "what is arr2 itself?: " << arr2 << endl ;  // unitialized memory, same as arr2[0]

  int *arr_p ;
  arr_p = new int[capacity] ;   // heap-allocated arrays can take advantage of variable parameters 
  for (int i = 0; i < capacity; ++i) 
    arr_p[i] = i * 3 ;
  // inspect the values
  for (int i = 0; i < capacity; ++i) 
    cout << arr_p[i] << "\t" ;
  cout << endl ;

  // how do we grow the capacity? 

  int *tmp = new int[capacity*2] ; 

  for (int i = 0; i < capacity; ++i)
    tmp[i] = arr_p[i];
  
  delete[] arr_p ;

  for (int i = 0; i < capacity; ++i) 
    cout << tmp[i] << "\t" ;
  cout << endl ;

  /***************************************************************/

  vector<int> v ; 

  cout << "Miscellaneous operations on vectors, unrelated to above..." << endl ;
  cout << "Empty vector properties: " << endl ;
  cout << "max size: " << v.max_size() << endl ;
  cout << "capacity: " << v.capacity() << endl ;
  cout << "size: " << v.size() << endl ;
  // VS treats calls to front() and back() on empty vectors as runtime exceptions
  // One solution is to make it the client's responsibility to check: 
  cout << "Is it empty? ( 0 = false, 1 = true) : "  << v.empty() << endl ; 
  if ( ! v.empty() ) {
    cout << "front: " << v.front() << endl ;
    cout << "back: " << v.back() << endl ;
  }


  v.push_back( 5 ) ;
  v.push_back( 10 ) ;
  v.push_back( 15 ) ;
  v.push_back( 20 ) ;
  cout << "capacity: " << v.capacity() << endl ;
  cout << "size: " << v.size() << endl ;

  v.insert(v.begin(), 7);
  cout << "capacity: " << v.capacity() << endl ;
  cout << "size: " << v.size() << endl ;

  cout << "v.front: " << v.front() << endl ;
  cout << "v.back: " << v.back() << endl ;
  v.pop_back() ; 
  cout << "v.back: " << v.back() << endl ;

  cout << "capacity: " << v.capacity() << endl ;
  cout << "size: " << v.size() << endl ;

  cout << "Tracking size vs capacity over the course of 100 push_back() operations: " << endl ; 
  for (int i = 0; i < 100; ++i) {
    v.push_back(i) ;
    if (i % 10 == 0 ) {
      cout << "capacity: " << v.capacity() << endl ;
      cout << "size: " << v.size() << endl ;
    }      
  }

  system( "PAUSE" ) ;
  return 0 ;

}