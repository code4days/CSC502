#include "sort.h"
#include<algorithm>

/**
* File Name: sort.cpp
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 02/09/2015
*/

using namespace std;


/**
* selection sort algorithm for sorting arrays
*/

void sortArray(int intArray[SIZE]) {
    int temp = 0;

    for (int i = 0; i < SIZE - 1; i++) {

        for (int j = i + 1; j < SIZE; j++) {

            if (intArray[i] > intArray[j]) {
                temp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = temp;
            }
        }
    }
}


/**
* selection sort algorithm for sorting vectors
*/

void sortVector(vector<int> &int_vector) {

    int temp = 0;

    for (int i = 0; i < int_vector.size() - 1 ; ++i) {

        for (int j = i + 1; j < int_vector.size(); ++j) {

            if (int_vector[i] > int_vector[j]) {
                temp = int_vector[i];
                int_vector[i] = int_vector[j];
                int_vector[j] = temp;
            }

        }

    }
}


/**
* Function to sort arrays using the built-in sort function
*/
void builtinArraySort(int intArray[]) {

    sort(intArray, intArray + SIZE);

}

/**
* Function to sort vectors using the built-in sort function
*/
void builtinVectorSort(vector<int> &intVector) {

    sort(intVector.begin(), intVector.end());

}


//improvement : create swap function and put swap logic there and call that function in sort functions


