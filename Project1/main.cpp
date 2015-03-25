#include <iostream>
#include <ctime>
#include "sort.h"

/**
* File Name: main.cpp
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 02/09/2015
*/
using namespace std;

int main() {

    int intArray[SIZE];
    vector<int> intVector;

    long startTime, endTime;

    srand (time(NULL));



    cout << endl;
    cout << "Current SIZE of array and vector: " << SIZE << endl;
    cout << endl;

    int tests = 1; //var for counting the number of tests performed

    while (tests <= 3) {

        /**
        * populate array and vector with random numbers
        */

        intVector.clear();
        for (int i = 0; i < SIZE; ++i) {

            intArray[i] = rand() % RAND_MAX;
            intVector.push_back(rand() % RAND_MAX);

        }

        cout << "Test #: " << tests << endl;
        cout << endl;

        /**
        * Sort integer array using selection sort algorithm
        * capture time in milliseconds before and after
        */

        startTime = clock();

        sortArray(intArray);

        endTime = clock();

        cout << "Sorting time for integer array: " << (endTime - startTime) * 1000 << " milliseconds" << endl;

        cout << endl;

        /**
        * Sort a vector using selection sort algorithm
        * capture time in milliseconds before and after
        */

        startTime = clock();

        sortVector(intVector);

        endTime = clock();

        cout << "Sorting time for integer vector: " << (endTime - startTime) * 1000 << " milliseconds" << endl;

        cout << endl;

        /**
        * Sort an array using built-in sort algorithm
        * capture time in milliseconds before and after
        */

        startTime = clock();

        builtinArraySort(intArray);//no need for the extra function, can call built-in sort directly from here

        endTime = clock();

        cout << "Storting time for integer array sort using builtin sort: " << (endTime - startTime) * 1000 << " milliseconds" << endl;

        cout << endl;

        /**
        * Sort a vector using built-in sort algorithm
        * capture time in milliseconds before and after
        */

        startTime = clock();

        builtinVectorSort(intVector); //no need for the extra function, can call built-in sort directly from here

        endTime = clock();

        cout << "Sorting time for integer vector using built-in sort: " << (endTime - startTime) * 1000 << " milliseconds" << endl;

        cout << endl;
        cout << "=====================" << endl;
        cout << endl;

        tests++;

    }
    return 0;
}