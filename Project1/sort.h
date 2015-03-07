
/**
* File Name: sort.h
* Author: Rasheed El-Saleh
* Course: CSC 502
* Date: 02/09/2015
*/
#include <vector>

#ifndef SORT_H
#define SORT_H

#define SIZE 1000 //1000, 10000, 100000
void sortArray(int intArray[]);
void sortVector(std::vector<int> &integerVector);
void builtinVectorSort(std::vector<int> &intVector);
void builtinArraySort(int intArray[]);

#endif