#include "sort.h"

// forward declarations for plugging in quickSort 
void quickSort(vector<int> & v, int left, int right) ; 
void quickSort(int arr[], int left, int right) ;
void swap(vector<int> & v, int i, int j) ;
int partition(vector<int> & v, int left, int right) ;

#define SELECTION    // allows for an easy switch from selection sort to QuickSort

void sort( vector<int> & v ) {

#ifndef SELECTION
	quickSort(v, 0, v.size()-1) ; 
#else 
	size_t i,j, min ;
  int tmp;
	for (j = 0; j < v.size(); j++) {
		min = j;
		for ( i = j+1; i < v.size(); i++) {
			if (v[i] < v[min]) {
				min = i;
			}
		}
 
		if(min != j) {
			tmp = v[j] ;
			v[j] = v[min] ;
			v[min] = tmp;
		}
	}
#endif // SELECTION
}

void sort( int arr[], int size ) {

#ifndef SELECTION
	quickSort(arr, 0, size-1) ;
#else
	  size_t i,j, min ;
    int tmp;

	  for (j = 0; j < size; j++) {
		  min = j;
		  for ( i = j+1; i < size; i++) { 
			  if (arr[i] < arr[min]) {
				  min = i;
			  }
		  }

		  if(min != j) {
			  tmp = arr[j] ;
			  arr[j] = arr[min] ;
			  arr[min] = tmp;
		  }
	  }  
#endif // SELECTION

}



void quickSort(int arr[], int left, int right)
{
    int l = left, r = right;
    int temp;
    int pivot = arr[(left + right) / 2];
    
    // Partition
    while (l <= r) {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r) {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    };
    
    // Recursion
    if (left < r)
        quickSort(arr, left, r);
    if (l < right)
        quickSort(arr, l, right);
}


void quickSort(vector<int> & v, int left, int right)
{
    if (left >= right) return;
    
    int part = partition(v, left, right);
    
    quickSort(v, left, part-1);
    quickSort(v, part+1, right);
}

void swap(vector<int> & v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int partition(vector<int> & v, int left, int right)
{
    int x = left;
    for (int i = x+1; i <= right; ++i)
    {
        if (v[i] < v[x])
        {
            swap(v, i, x);
            if (i != x+1)
            {
                swap(v, i, x+1);
            }
            x = x + 1;
        }
    }
    return x;
}