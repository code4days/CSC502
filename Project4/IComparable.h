/**
* File Name: IComparable.h
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/06/2015
*/


#ifndef _ICOMPARABLE_H
#define _ICOMPARABLE_H

#include <iostream>

using namespace std;

/**
* IComparable abstract base class, includes compare and print pure virtual functions
* and comparision operator overrides
*/
class IComparable {

public:

    /**
    * pure virtual compare function for comparing IComparale objects
    * will be implemented in derived classes
    */
    virtual int compare(const IComparable &icmp) const  = 0;

    /**
    * pure virtual function for printing
    * will be implemented in derived classes
    */
    virtual void print(ostream &out= cout) const = 0;

    /**
    * virtual operator comparison functions
    */
    virtual bool operator< (const IComparable &rhs) const {
        return (compare(rhs) < 0);
    }

    virtual bool operator> (const IComparable &rhs) const {
        return (compare(rhs) > 0);
    }

    virtual bool operator== (const IComparable &rhs) const {
        return (compare(rhs) == 0);
    }

    virtual bool operator<= (const IComparable &rhs) const {
        return (compare(rhs) <= 0);
    }

    virtual bool operator>= (const IComparable &rhs) const {
        return (compare(rhs) >= 0);
    }

    virtual bool operator!= (const IComparable &rhs) const {
        return (compare(rhs) != 0);
    }

    /**
    * pure virtual operator= override, will be implemented in derived class
    */

    virtual const IComparable &operator=(const IComparable &rhs) =0;

    /**
    * IComparable destructor
    */

    virtual ~IComparable() {

    }
};

/**
* External operator<< override calls IComparable print function for printing value
*/
ostream &operator<<(ostream &out, const IComparable &ic) {
    ic.print(out);
    return out;
}

/**
* Integer class for comparing integers, inherits from IComparable
*/

class Integer : public IComparable {

public:

    /**
    * Integer constructor initilizes data member value
    */
    Integer(int int_value = 0)
            : value(int_value) {
    }

//    Integer(const IComparable &source)
//            :value(dynamic_cast<const Integer &>(source).value) {
//
//    }

    /**
    * Integer class destructor
    */
    virtual ~Integer() {
    }

    /**
    * Implementation of inherited function completed, compares two integers
    */
    virtual int compare(const IComparable &rhs) const {
        int rhs_value = dynamic_cast<const Integer &>(rhs).value;

        return (value < rhs_value) ? -1 : (value > rhs_value);
    }

    /**
    * print Integer value
    */

    void print(ostream &out = cout) const {
        out << value;
    }

    /**
    * implementation of inherited operator= override with IComparible reference passed in
    */

    const Integer &operator=(const IComparable &rhs) {

        if(this != &rhs) {
            value = dynamic_cast<const Integer &>(rhs).value;
        }

        return *this;
    }

    /**
    * implementation of operator= override with Integer reference passed in
    */
    const Integer &operator=(const Integer &rhs) {
        if(this != &rhs) {
            value = rhs.value;
        }
        return *this;
    }

private:
    int value;

};


/**
* Character constructor initilized data member value
*/
class Character : public IComparable {

public:

    /**
    * Character constructor initilizes data member value
    */
    Character(char char_value = '?')
            : value(char_value) {
    }

//    Character(const IComparable &source)
//            :value(dynamic_cast<const Character &>(source).value) {
//
//    }

    /**
    * Character class destructor
    */
    virtual ~Character() {
    }

    /**
    * Implementation of inherited function completed, compares two characters
    */
    virtual int compare(const IComparable &rhs) const {
        char rhs_value = dynamic_cast<const Character &>(rhs).value;

        return (value < rhs_value) ? -1 : (value > rhs_value);
    }

    void print(ostream &out = cout) const {
        out << value;
    }

    /**
    * implementation of inherited operator= override with IComparible reference passed in
    */
    const Character &operator=(const IComparable &rhs) {

        if(this != &rhs) {
            value = dynamic_cast<const Character &>(rhs).value;
        }

        return *this;
    }

    /**
    * implementation of operator= override with Character reference passed in
    */
    const Character &operator=(const Character &rhs) {
        if(this != &rhs) {
            value = rhs.value;
        }

        return *this;
    }

private:
    char value;

};

/**
* functor for using IComparable with std::sort
*/
struct compare_functor {
    bool operator() (const IComparable *v1, const IComparable *v2) {
        return (*v1 < *v2);
    }
}lessThan;
#endif