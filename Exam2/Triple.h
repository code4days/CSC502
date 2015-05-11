//
// Created by Rasheed ElSaleh on 4/19/15.
//

/*
Write a class template called Triple that allows the user to package any
three arbitrary (non-pointer) data types together and provides access to
those data members via traditional accessors and mutators (getters and setters).
It should not be possible to directly access the data members and you must ensure
that accessors cannot change the data values.

You may assume that no specialized destructor is necessary, and you may omit the copy constructor.
 You must, however, provide a three-arg constructor and a print() function that displays the elements of the
 Triple in the format of your choice.
*/

/**
* File Name: Triple.h
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 03/19/2015
*/

#ifndef TRIPLE_H
#define TRIPLE_H

#include <iostream>

using namespace std;

template <typename T1, typename T2, typename T3>
class Triple {

public:
    Triple(const T1 &initT1, const T2 &initT2, const T3 &initT3)
            :t1(initT1), t2(initT2), t3(initT3) {}

    void print(ostream &out = cout) const {
        out << "First: " << t1 << "\nSecond: " << t2 << "\nThird " << t3;
        out << endl;
    }

    T1 getT1() const {
        return t1;
    }

    void setT1(T1 t1) {
        Triple::t1 = t1;
    }

    T2 getT2() const {
        return t2;
    }

    void setT2(T2 t2) {
        Triple::t2 = t2;
    }

    T3 getT3() const {
        return t3;
    }

    void setT3(T3 t3) {
        Triple::t3 = t3;
    }

private:
    T1 t1;
    T2 t2;
    T3 t3;

};

/*template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &out, const Triple<T1, T2, T3> &t) {
    t.print(out);
    return out;
}*/
//overload operator <<

#endif //TRIPLE_H
