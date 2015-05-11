/**
* File Name: Comparable.h
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/15/2015
*/

#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

#include <ostream>

using namespace std;

/*
 * Assumptions:
 * Comparable template datatypes include most primitive types such as int, char, long, float
 * and double. It will also compare strings and custom objects that compare specific datatype values.
 * The Comparable template will not work with custom objects that require special comparison functions.
 * It will also not work with pointers since we do not implement the big three.
 * Comparison can only be done with the overloaded operators included.
 */
template <typename T>
class Comparable {

public:

    Comparable(const T &initValue)
            :value(initValue) {

    }

    /**
   *  operator comparison function overloads
   */
    bool operator< (const Comparable &rhs) const {
        return (value < rhs.value);
    }

    bool operator> (const Comparable &rhs) const {
        return (value > rhs.value);
    }

    bool operator== (const Comparable &rhs) const {
        return (value == rhs.value);
    }

    bool operator<= (const Comparable &rhs) const {
        return (value <= rhs.value);
    }

    bool operator>= (const Comparable &rhs) const {
        return (value >= rhs.value);
    }

    bool operator!= (const Comparable &rhs) const {
        return (value != rhs.value);
    }

    /*
     * print function to print object value.
     */
    void print(ostream &out = cout) const {
       out << value;
   }


private:
   T value;
};

/**
 * template function assumptions:
 * datatypes that work with the Comparable template class will work with this function
 * these include most primitive types such as int, char, long, float. It will also work with strings
 * pointers are excluded b/c they aren't part of Comparable's implementation
 */
template <typename T>
ostream &operator<<(ostream &out, const Comparable<T> &c) {
    c.print(out);
    return out;
}

#endif //ICOMPARABLE_H
/**
 * 502 Additional Requirement:
 * The vectors contain Comparable objects of primitive types
 * By overloading the < operator in the Comparable class above and comparing the values we were
 * able to use std::sort(...); without the additional function argument.
 */