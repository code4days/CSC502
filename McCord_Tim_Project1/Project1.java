import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays; // CSC 502 only

public class Project1 {

	// class (global) scope
	static final int SIZE = 100000;
	
	// For convenience, define RAND_MAX to mimic C++ rand() method
	static final int RAND_MAX = 32767;

	
	public static void main(String[] args) {

		int[] intArray = new int[SIZE];
		ArrayList<Integer> integerArrayList = new ArrayList<Integer>(SIZE);
		long start, end;

		// The Random object provides an easy method to generate integers
		//   in a given range; it should be seeded with the current time
		Random r = new Random(System.currentTimeMillis());

		for (int i = 0; i < SIZE; ++i)
			intArray[i] = r.nextInt(RAND_MAX);  // range 0-32767

		for (int i = 0; i < SIZE; ++i)
			integerArrayList.add(new Integer(r.nextInt(RAND_MAX)));

		// early test runs may use this to verify sort logic
		if (SIZE <= 10) {
			System.out.println("\nint Array before sorting");
			for (int i = 0; i < SIZE; ++i)
				System.out.println(intArray[i]);
		}

		if (SIZE <= 10) {
			System.out.println("\nInteger ArrayList before sorting");
			for (int i = 0; i < SIZE; ++i)
				System.out.println(integerArrayList.get(i));
		}

		// primitive int array test
		start = System.currentTimeMillis();
		sort(intArray);
		end = System.currentTimeMillis();
		System.out.println("intArray isSorted: " + isSorted(intArray)) ;
		System.out.println("Elapsed time for sorting primitive array of "
				+ SIZE + " elements: " + (end - start));

		// ArrayList test
		start = System.currentTimeMillis();
		sort(integerArrayList);
		end = System.currentTimeMillis();
		System.out.println("integerArrayList isSorted: " + isSorted(integerArrayList)) ;
		System.out.println("Elapsed time for sorting ArrayList of Integers of "
				+ SIZE + " elements: " + (end - start));

		System.out.println("\nCSC 502 additions");
		System.out.println("==================================");
				
		// CSC 502 only....
		// reinitialize array with random ints
		for (int i = 0; i < SIZE; ++i)
			intArray[i] = r.nextInt(RAND_MAX);
		//System.out.println("intArray isSorted: " + isSorted(intArray)) ;
		start = System.currentTimeMillis();
		Arrays.sort(intArray);
		end = System.currentTimeMillis();
		System.out.println("intArray isSorted: " + isSorted(intArray)) ;
		System.out.println("Elapsed time for built-in sort of primitive array of "
				+ SIZE + " elements: " + (end - start));
		
		// CSC 502 only....
		// reinitialize ArrayList with random ints
		integerArrayList.clear() ;
		for (int i = 0; i < SIZE; ++i)
			integerArrayList.add(new Integer(r.nextInt(RAND_MAX)));
		// check to make sure it was reinitialized properly
		//System.out.println("integerArrayList isSorted: " + isSorted(integerArrayList)) ;
		start = System.currentTimeMillis();
		integerArrayList.sort(null) ;
		end = System.currentTimeMillis();
		System.out.println("integerArrayList isSorted: " + isSorted(integerArrayList)) ;		
		System.out.println("Elapsed time for built-in sort with an ArrayList of integers of "
						+ SIZE + " elements: " + (end - start));

		if (SIZE <= 10) {
			System.out.println("\nint Array after sorting");
			for (int i = 0; i < SIZE; ++i)
				System.out.println(intArray[i]);
		}

		if (SIZE <= 10) {
			System.out.println("\nInteger ArrayList after sorting");
			for (int i = 0; i < SIZE; ++i)
				System.out.println(integerArrayList.get(i));
		}

	} // end of main method
	

	public static void sort(int[] arr) {
		// selection sort, which looks virtually identical in Java and C/C++
		int i, j, min, tmp;
		for (j = 0; j < arr.length; j++) {
			/* assume the min is the first element */
			min = j;
			/* test against elements after j to find the smallest */
			for (i = j + 1; i < arr.length; i++) {
				/* if this element is less, then it is the new minimum */
				if (arr[i] < arr[min]) {
					min = i;
				}
			}
			// swap if we have a new min
			if (min != j) {
				tmp = arr[j];
				arr[j] = arr[min];
				arr[min] = tmp;
			}
		}

	} // end of sort( int[] arr ) method

	public static void sort(ArrayList<Integer> arrList) {
		int i, j, min;
		Integer tmp;
		for (j = 0; j < arrList.size(); j++) {
			// assume the min is the first element
			min = j;
			// test against elements after j to find the smallest
			for (i = j + 1; i < arrList.size(); i++) {

				// if this element is less, then it is the new minimum
				if (arrList.get(i) < arrList.get(min)) {
					min = i;
				}
			}

			//swap if there is a new min
			if (min != j) {
				tmp = arrList.get(j);
				arrList.set(j, arrList.get(min));
				arrList.set(min, tmp);
			}
		}
	}
	
	public static boolean isSorted(int[] arr) {
		for (int i = 0; i < SIZE - 1; ++i) {
			if (arr[i] > arr[i + 1])
				return false;
		}
		// fall-through case 
		return true;
	} // end of isSorted(int[] arr)
	
	public static boolean isSorted( ArrayList<Integer> arrList ) {
		for (int i = 0; i < SIZE - 1; ++i) {
			if ( arrList.get(i) > arrList.get(i+1) )
				return false;
		}
		// fall-through case 
		return true;
	} // end of isSorted(ArrayList<Integer> arrList)
	
} // end of class

/*

All times are in milliseconds using JRE 1.8 (latest patch level).  
My implementation used selection sort to intentionally maximize the sheer number
of operations, but notice that the Java built-in sort (CSC 502 only) uses a much more efficient algorithm, guaranteed
to be O n log2 n.  
The machine is a 4-core i5 @ 3.10 GHz, though only the built-in sorts could potentially take advantage 
of multiple cores.  

1)  Three runs w/ SIZE = 1000 

intArray isSorted: true
Elapsed time for sorting primitive array of 1000 elements: 0
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 1000 elements: 31

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 1000 elements: 0
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 1000 elements: 0



intArray isSorted: true
Elapsed time for sorting primitive array of 1000 elements: 0
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 1000 elements: 16

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 1000 elements: 0
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 1000 elements: 0



intArray isSorted: true
Elapsed time for sorting primitive array of 1000 elements: 0
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 1000 elements: 15

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 1000 elements: 0
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 1000 elements: 0



2)  Three runs with SIZE = 10000


intArray isSorted: true
Elapsed time for sorting primitive array of 10000 elements: 47
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 10000 elements: 125

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 10000 elements: 15
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 10000 elements: 0



intArray isSorted: true
Elapsed time for sorting primitive array of 10000 elements: 32
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 10000 elements: 124

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 10000 elements: 16
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 10000 elements: 0



intArray isSorted: true
Elapsed time for sorting primitive array of 100000 elements: 3790
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 100000 elements: 11327

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 100000 elements: 31
integerArrayList isSorted: false
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 100000 elements: 47



3)  Three runs with SIZE = 100000

intArray isSorted: true
Elapsed time for sorting primitive array of 100000 elements: 3791
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 100000 elements: 11311

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 100000 elements: 31
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 100000 elements: 31



intArray isSorted: true
Elapsed time for sorting primitive array of 100000 elements: 3791
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 100000 elements: 11311

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 100000 elements: 31
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 100000 elements: 31



intArray isSorted: true
Elapsed time for sorting primitive array of 100000 elements: 3791
integerArrayList isSorted: true
Elapsed time for sorting ArrayList of Integers of 100000 elements: 11326

CSC 502 additions
==================================
intArray isSorted: true
Elapsed time for built-in sort of primitive array of 100000 elements: 31
integerArrayList isSorted: true
Elapsed time for built-in sort with an ArrayList of integers of 100000 elements: 31


 */

