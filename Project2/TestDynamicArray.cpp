/**
* File Name: TestDynamicArray.cpp
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/04/2015
*/

#include "DynamicArray.h"

using namespace std;

//todo: create functions for all the tests and call them from main.

int main() {
    //create DynamicArray instance with no arg
    DynamicArray d1;
    //create DynamicArray instance with array size specified
    DynamicArray d2 (10);

    cout << "Testing no arg/ default value constructor ( DynamicArray d1; DynamicArray d2 (10); ):" << endl;

    //print capacity and size for created instances
    cout << "DynamicArray d1 capacity: " << d1.capacity() << endl;
    cout << "DynamicArray d1 size: " << d1.size() << endl;

    cout << "DynamicArray d2 capacity: " << d2.capacity() << endl;
    cout << "DynamicArray d2 size: " << d2.size() << endl;
    cout << endl;

    //create primitive array to pass into Dynamic array constructor
    const int intArraycapacity = 10;
    int intArray[intArraycapacity];

    //populate array with values
    for(int i = 0; i < intArraycapacity; ++i) {
        intArray[i] = i * 2;
    }

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    //create instance of Dynamic array using primitive array
    DynamicArray d3(intArray, intArraycapacity);

    cout << "Testing DynamicArray constructor with primitive array arg: " << endl;
    cout << "Primitive array capacity: " << intArraycapacity << endl;
    cout << "DynamicArray d3 capacity: " << d3.capacity() << endl;
    cout << "DynamicArray d3 size: " << d3.size() << endl;

    cout << "DynamicArray d3 values: [\t";

    //loop through array and print values
    for(int i = 0; i < intArraycapacity; ++i) {
        cout << d3.get(i) << "\t";
    }
    cout << "]" << endl;


    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    //call operator= overloaded function to copy content of d3 to d1
    d1 = d3;
    cout << endl;
    cout << "Testing operator= overloading (d1 = d3): " << endl;
    cout << "DynamicArray d1 capacity after copy: " << d1.capacity() << endl;
    cout << "DynamicArray d1 size after copy : " << d1.size() << endl;
    cout << "DynamicArray d1 values: (was previously empty) [\t";

    //loop through array and print values
    if (d1.size() > 0) {
        for(int i = 0; i < intArraycapacity; ++i) {
            cout << d1.get(i) << "\t";
        }
    }
    cout << "]" << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Testing front() and back() member functions on d1: " << endl;

    //test the front() and back() member functions on DynamicArray d1
    cout << "DynamicArray d1 front: " << d1.front() << endl;
    cout << "DynamicArray d1 back: " << d1.back() << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Testing find() function: " << endl;

    //test finding a number in d1 using the find() member function
    int n = 10; //number to search for
    int index = 0; //location of number in array if found
    index = d1.find(n);
    if (index != -1) {
        cout << "number " << n << " was found in d1 at index "<< index << endl;
    }
    else {
        cout << "number was not found in d1 "  << endl;
    }

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    //test adding a value to array using push_back()
    cout << "Test push_back() member function on d1 (d1.push_back(65)): " << endl;
    cout << "d1 size before push_back(): " << d1.size() << endl;

    d1.push_back(65);
    cout << "d1 size after push_back: [\t " << d1.size() << endl;

    for(int i = 0; i < d1.size(); ++i) {
        cout << d1.get(i) << "\t";
    }
    cout << "]" << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    //test inserting number at specific position
    cout << "Test insert(4, 333) member function on d1: " << endl;
    if(d1.insert(4, 333) == -1) {
        cout << "Error inserting value in array" << endl;
    }
    else {
        cout << "Value inserted correctly..." << endl;
        cout << "DynamicArray d1 after insert(): " << endl;
        cout << "d1 values: [\t";

        for(int i = 0; i < d1.size(); ++i) {
            cout << d1.get(i) << "\t";
        }

        cout << "]" << endl;
    }
    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Test pop_back() to remove last value in array: " << endl;
    cout << "d1 size before pop_back(): " << d1.size() << endl;

    d1.pop_back();

    cout << "d1 size after pop_back(): " << d1.size() << endl;
    cout << "DynamicArray d1 after pop_back(): " << endl;
    cout << "d1 values: [\t";

    for(int i = 0; i < d1.size(); ++i) {
        cout << d1.get(i) << "\t";
    }
    cout << "]" << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Printing DynamicArray d1 using overloaded << operator: " << endl;
    cout << d1 << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    //test = operator overloading to make a copy of d1 and name it d6
    //test the overloaded == operator to see if the two object are equal
    cout << "Testing overloaded == operator and = operator to copy d1 to d4 then see if d1 == d4: " << endl;
    DynamicArray d4;
    d4 = d1;
    cout << "Printing array using overloaded << operator 'cout << d4 << endl;' " << endl;
    cout << d4 << endl;
    cout << ((d1 == d4) ? "d1 and d4 are equal" : "d1 and d4 are not equal") << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;


    //test using the overloaded + operator to concatenate the arrays of two object and
    cout << "Test operator + overloading (d1 + d3): "<< endl;
    DynamicArray d5 = (d1 + d3);

    cout << "d5 values: [\t";
    for(int i = 0; i < d5.size(); ++i) {
        cout << d5.get(i) << "\t";
    }
    cout << "]" << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Test to see if DynamicArray d6 is empty(): " << endl;
    DynamicArray d6;
    cout << (d6.empty() ? "d6 is empty" : "d6 is not empty") << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "Test clear() member function on d5: " << endl;

    cout << "d5 size before calling d5.clear() is:  " << d5.size() << endl;
    d5.clear();
    cout << "d5 size after calling d5.clear() is :  " << d5.size() << endl;

    cout << endl;
    cout << "=================================" << endl;
    cout << endl;

    return 0;
}