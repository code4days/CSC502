/**
* File Name: DynamicArray.cpp
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/04/2015
*/
#include "DynamicArray.h"

/**
* Implementation of operator= overloading
*/
const DynamicArray &DynamicArray::operator=(const DynamicArray &dArray) {

    if(this != &dArray) {

        int newSize = dArray.size();

        _size = newSize;
        _capacity = dArray.capacity();

        if(_size > 0) {
            for(int i = 0; i < newSize; ++i) {
                _arr[i] = dArray.get(i);
            }
        }
    }
    return *this;
}

/**
* Implementation of operator+ overloading
* concatenates two arrays and returns a copy of a new DynamicArray
*/
DynamicArray DynamicArray::operator+(const DynamicArray &dArray) {


    const int newCapacity = _capacity + dArray.capacity();
    int newSize = _size + dArray.size();

    int *tempArray = new int[newCapacity];

    for( int i = 0; i < dArray.size(); ++i) {
        tempArray[i] = dArray.get(i);
    }

    for(int i = dArray.size(); i < newSize; ++i) {
        tempArray[i] = get(i - dArray.size());
    }

    return DynamicArray(tempArray, newSize);
}

/**
* Implementation of operator== overloading
* returns true if both sides have the same values and sizes
*/
bool DynamicArray::operator==(const DynamicArray &rhs) {
    bool isEqual = 1;

    if( size() != rhs.size()) {
        return 0;
    }
    else {

        for(int i = 0; i < rhs.size() && isEqual; ++i) {

            if (find(get(i)) == -1 || rhs.find(get(i)) == -1) {
                return 0;
            }
        }

    }
    return isEqual;
}

//accessor member function returns value of member variable capacity
int DynamicArray::capacity() const {
    return _capacity;
}

//accessor member function returns value of member variable size
int DynamicArray::size() const {
    return _size;
}
//accessor member function returns true if member variable size is 0
bool DynamicArray::empty() const {
    return (_size == 0);
}

//accessor member function returns first value in member array
int DynamicArray::front() const {
    return _arr[0];
}

//accessor member function returns last value of member array
int DynamicArray::back() const {
    return _arr[size() - 1];
}

//accessor member function returns the index of the value passed in -1 otherwise
int DynamicArray::find(int val) const {

    for(int i = 0; i < size(); ++i) {
        if(val == _arr[i]) {
            return i;
        }
    }
    return -1;
}

//accessor member function return the value of a specific location in the array
int DynamicArray::get(int index)const {
    return _arr[index];
}

//mutator member function sets the size member variable to 0
void DynamicArray::clear() {
    _size = 0;
}

//mutator member function to set the capacity
void DynamicArray::set_capacity(int _capacity) {
    DynamicArray::_capacity = _capacity;
}

//mutator member function to set the size
void DynamicArray::set_size(int _size) {
    DynamicArray::_size = _size;
}

/**
* member function to add a value at the end of the array
* populates temp array, deletes member array then points member array to the temp array
*/
void DynamicArray::push_back(int val) {

    int tempCapacity = _capacity;
    int tempVal = 0;

    if( _capacity - _size <= 2) {
        tempCapacity = _capacity + 3;
    }
    int *tmp = new int [tempCapacity];

    for(int i = 0; i < _capacity; ++i) {
        tmp[i] = _arr[i];
    }

    tmp[_size] = val;

    delete [] _arr;

    _arr = tmp;

    set_size(_size + 1);
    set_capacity(tempCapacity);
}

/**
* member function to add a value at the given position of the array
* populates temp array, deletes member array then points member array to the temp array
*/
int DynamicArray::insert(int pos, int val) {
    int result = -1;

    if(pos <= _capacity) {

        int currentSize = size();
        int currentCapacity = capacity();


        int tempCapacity = currentCapacity;

        int tempVal = 0;

        if( currentCapacity - currentSize <= 2) {
            tempCapacity = currentCapacity + 3;
            set_capacity(tempCapacity);
        }

        cout << "TEMP CAP: " << tempCapacity << endl;
        cout << "CURRENT SIZE " << currentSize << endl;
        int *temp = new int[tempCapacity];

        for(int i = 0; i <= currentSize; ++i) {

            if(i < pos) {
                temp[i] = get(i);
            }
            if(i == pos) {
                temp[i] = val;
            }
            if(i > pos) {
                temp[i] = get(i - 1);
            }
        }

        delete [] _arr;

        _arr = temp;

        set_size(_size + 1);
        result = 1;
    }
    return result;

}

/**
* remove last value from the array and decrease size by one
*/
void DynamicArray::pop_back() {

    _arr[_size - 1] = 0;
    set_size(--_size);
}

/**
* member function to print values of member array
*/
void DynamicArray::print(ostream &out) const {
    for(int i = 0; i < _size; ++i) {
        out << _arr[i] << "\t";
    }
}

/**
* Non member function implementation of operator<< overloading
* takes a reference to a DynamicArray and calls the print function to print the values.
*/
ostream& operator<<(ostream &out, const DynamicArray &dArray) {
    dArray.print(out);
    return out;
}