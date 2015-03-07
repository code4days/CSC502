import java.util.*;

/**
 * File Name: Project1.java
 * Author: Rasheed El-Saleh
 * Course: CSC 502
 * Date: 02/09/2015
 */


public class Project1 {

    private static final int SIZE = 1000; //1000, 10000, 100000
    private static int[] intArray = new int[SIZE];

    private static ArrayList<Integer> intArrayList = new ArrayList<Integer>(SIZE);

    private static Random rand = new Random();

    private static long startTime = 0;

    private static long endTime = 0;


    public static void main(String[] args) {

        /**
         * populate array and ArrayList with random numbers
         */

        for (int i = 0; i < SIZE; i++) {

            intArrayList.add(rand.nextInt(32767));
            intArray[i] = rand.nextInt(32767);
        }

        System.out.println();
        System.out.println("Current SIZE of array and ArrayList: " + SIZE);
        System.out.println();


        int tests = 1; //var for counting the number of tests performed

        while(tests <= 3) {


            System.out.println("Test #: " + tests);
            System.out.println();

            /**
             * Sorting Array using selection sort algorithm
             * capture time in milliseconds before and after
             */

            startTime = System.currentTimeMillis();

            sortArray(intArray);

            endTime = System.currentTimeMillis();

            System.out.println("Sorting time for integer array: " + (endTime - startTime) + " milliseconds");

            System.out.println();

            /**
             * Soring an ArrayList using selection sort algorithm
             * capture time in milliseconds before and after
             */

            startTime = System.currentTimeMillis();

            sortArrayList(intArrayList);

            endTime = System.currentTimeMillis();

            System.out.println("Sorting time for ArrayList<Integer>: " + (endTime - startTime) + " milliseconds");

            System.out.println();

            /**
             * Sorting Array using built-in sort algorithm
             * capture time in milliseconds before and after
             */

            startTime = System.currentTimeMillis();

            builtInSortArray(intArray);

            endTime = System.currentTimeMillis();


            System.out.println("Sorting time for integer array using built-in sort: " + (endTime - startTime) + " milliseconds");

            System.out.println();

            /**
             * Sorting ArrayList using built-in sort
             * capture time in milliseconds before and after
             */

            startTime = System.currentTimeMillis();

            buildInSortArrayList(intArrayList);

            endTime = System.currentTimeMillis();

            System.out.println("Sorting time for ArrayList<Integer> using built-in sort: " + (endTime - startTime) + " milliseconds");

            System.out.println();
            System.out.println("=====================");
            System.out.println();

            tests++;
        }
    }


    /**
     * method to sort arrays using Selection Sort
     * @param integerArray
     */
    private static void sortArray(int[] integerArray) {
        int temp = 0;

        for (int i = 0; i < integerArray.length - 1; i++) {

            for (int j = i + 1; j < integerArray.length; j++) {

                if (integerArray[i] > integerArray[j]) {
                    temp = integerArray[i];
                    integerArray[i] = integerArray[j];
                    integerArray[j] = temp;
                }
            }
        }
    }


    /**
     * method to sort ArrayLists using the selection sort algorithm
     * @param integerArrayList
     */
    private static void sortArrayList(ArrayList<Integer> integerArrayList) {
        int temp = 0;

        for (int i = 0; i < integerArrayList.size() - 1; i++) {

            for (int j = i + 1; j < integerArrayList.size(); j++) {

                if (integerArrayList.get(i) > integerArrayList.get(j)) {
                    temp = integerArrayList.get(i);
                    integerArrayList.set(i, integerArrayList.get(j));
                    integerArrayList.set(j, temp);
                }

            }

        }
    }

    /**
     * method for sorting an array using the built-in Arrays.sort method
     * @param integerArray
     */
    private static void builtInSortArray(int[] integerArray) {

        Arrays.sort(integerArray);

    }

    /**
     * method for sorting an ArrayList using the built-in Collections.sort method
     * @param integerArrayList
     */
    private static void buildInSortArrayList(ArrayList<Integer> integerArrayList) {

        Collections.sort(integerArrayList);
    }

}
