/**
* File Name: DynamicArray.h
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/04/2015
*/

#ifndef _DYNAMICARRAY_H
#define _DYNAMICARRAY_H
#include <iostream>

using namespace std;

class DynamicArray {

public:

    //Constructors
    /**
    * single arg constructor can also be no arg constructor due to the default value
    */
    explicit DynamicArray(int arrayCapacity = 10)
        :_capacity(arrayCapacity) {

        _arr = new int[_capacity];
        _size = 0;
        //Question: do i need to initilize array values to 0?
    }

    /**
    * 2 arg constructor that takes in an array and it's length and initializes the member array with the values of the passed in array
    */
    DynamicArray(const int intArray[], int arraySize) {
        _arr = new int[arraySize];
        for (int i = 0; i < arraySize; ++i) {
            _arr[i] = intArray[i];
        }
        _size = arraySize;
        _capacity = arraySize;
    }

    /**
    * Big three copy constructor
    */
    DynamicArray(const DynamicArray &dArray) {

        _size = dArray.size();
        _capacity = dArray.capacity();
        _arr = new int[_capacity];

        if(_size > 0) {
            for(int i = 0; i < dArray.size(); ++i) {
                _arr[i] = dArray.get(i);
            }
        }

    }

    //operator definitions
    /**
    * Big three operator= overloading
    */
    const DynamicArray &operator=(const DynamicArray &dArray);

    /**
    * operator+ overloading definition
    */
    DynamicArray operator+(const DynamicArray &dArray);

    /**
    * definition for operator== overloading
    */
    bool operator==(const DynamicArray &rhs);

    /**
    * Big three destructor for class
    */
    ~DynamicArray() {
        delete[] _arr;
    }

    /**
    * Member functions definitions
    */
    int capacity() const;
    int size() const;
    bool empty() const;
    int front() const;
    int back() const;
    int find(int val) const;
    int get(int index)const;
    void clear();
    void set_capacity(int _capacity);
    void set_size(int _size);
    void push_back(int val);
    int insert(int pos, int val);
    void pop_back();
    void print(ostream &out = cout) const;

private:
    int _capacity;
    int _size;
    int *_arr;
};

//non member operator<< overload definition
ostream& operator<<(ostream &out, const DynamicArray &dArray);
#endif