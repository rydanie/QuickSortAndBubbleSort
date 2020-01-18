/*
    ENGR2400 Data Structures and Algorithms
    Fall 2019
    Ryley Danielson
    Programming Assignment 4 - Bubble sort and Quick sort
    The goal of this assignment is to sort a list of inputs both sorted and unsorted, long and short and calculate number of comparisons and runtime.";
*/

//Librayies required to perform program functions
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 
#include <chrono> 

using namespace std; //Namespace for standard functions
using namespace chrono; //Namespace for timestamp functions

int smallSize = 0; //Number of values in the small list
long int largeSize = 0; //Number of values in the large list
long int compare = 0; //Counts number of comparisons in an algorithm
int* large; //Large aray
int* small; //Small array
long int bubCompSU, bubCompSS, bubCompLU, bubCompLS, quickCompSU, quickCompSS, quickCompLU, quickCompLS; //Stores comparison values for each algorithm and list
ifstream smallfile; //File stream for small input 
ifstream largefile; //File stream for large input
ofstream smallOutputfile; //File stream for small output 
ofstream largeOutputfile; //File stream for large output

/*
  Swap function used by both bubble sort and quick sort
  Swaps the location of two varibles in a list
*/
void swap(int* a, int* b)
{
    int temp = *a; // temp value to hold the first element
    *a = *b;       // set the first element equvalent to the second
    *b = temp;     // set the second elemt equivalent to the first
}

/*
  This function performa a bubble sort on a set of input data, that being the array arr and the size of the array n
  The data is sorted from least to greatest
  The number of cmparisons made by the algorithm tracked by the "compare" incrementor
*/
void bubbleSort(int arr[], int n)
{
    int i, j;  //Temp variables to store values              
    bool swapped = false; //Boolean check used to break te for loop when the set is sorted
   
        swapped = false;
        for (i = 0; i < n - 1; i++) //Outer loop that grabbs one element from the set to sort
        {
            for (j = 0; j < n - i - 1; j++)//Inner loop from which otter loop values are compared and swapped
            {
                compare++;
                if (arr[j] > arr[j + 1]) //Checks if the left element is reater than the right element and swapps them if true
                {
                    swap(&arr[j], &arr[j + 1]); 
                    swapped = true;
                }
                
            }
            if (swapped == false) //Checks if ay swaps have occured in the last iteration
            {
                break;
            }
        }
    
}




/* 
  This function quick sort function
  It takes last element as pivot
  All smaller values are placed left and greater are placed to the right of the pivot
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  

    for (int j = low; j <= high - 1; j++) // Check if current element is smaller than the pivot 
    {
        compare++; 
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]); // Swap elements as per the condition
        }
    }
    swap(&arr[i + 1], &arr[high]); // Swap elements as per the condition
    return (i + 1);
}

/* 
  This functio implements QuickSort
  arr[] is defined as the array to be sorted
  low is defined as the starting index
  high is defined as the ending index 
  This algoithm is recursive and uses the partition algoithm in its implementation
*/
void quickSort(int arr[], int low, int high)
{
    compare++;
    if (low < high)
    {
        //pi is partitioning index
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); //elements before original partition
        quickSort(arr, pi + 1, high); //eleements after original partition
    }
}

/*
  Reads data from the file with a small data set
  Finds the number of elements in the array, allocates that place to the array, then populates the array
*/
void readSmallInput() 
{
    smallfile.open("Small_Random_Output.txt"); //open file
    int size = 0;
    string s; //placeholder for iterating through the file
    if (smallfile.is_open())                     //if the file is open
    {
        while (!smallfile.eof())                 //while the end of file is NOT reached
        {
            getline(smallfile,s); //Does nothing besides iterate through the file
            size++; // iterator
        }
        smallfile.close(); //close file

        size--; //account for extra space at the end of the file
        smallSize = size;
        small = new int[size]; //allocate space for the array

        smallfile.open("Small_Random_Output.txt"); //open file
     
        for (int i = 0; i < size; i++) //loop that populates the array
        {
            smallfile >> small[i];
        }

        smallfile.close();//close file  
    }
    else
    {
        cout << "Unable to open file";       //if the file is not open 
    }
}

/*
  Reads data from the file with a large data set
  Finds the number of elements in the array, allocates that place to the array, then populates the array
*/
void readLargeInput()
{
    largefile.open("Large_Random_Output.txt"); //open file
    string s; //placeholder for iterating through the file
    int size = 0;
    if (largefile.is_open())                     //if the file is open
    {
        while (!largefile.eof())                 //while the end of file is NOT reached
        {
            getline(largefile, s); //Does nothing besides allow for iteration through the file
            size++;                //get one line from the file
        }
        largefile.close(); //close file

        size--; //accounts for extra line in file
        largeSize = size;
        large = new int[size]; // allocates place for array

        largefile.open("Large_Random_Output.txt"); //open file
        for (int i = 0; i < size; i++) //loop for populating the array
        {
            largefile >> large[i]; 
        }
        largefile.close();//closing the file
    }
    else
    {
        cout << "Unable to open file";       //if the file is not open output 
    }
}

/*
  Calls file input methods, sorting algorithms, and outputs sorted listes with runtimes and comparisons
*/
int main(void)
{
    cout << "ENGR2400 Data Structures and Algorithms\nFall 2019\nRyley Danielson\nProgramming Assignment 4 - Bubble Sort and Quick Sort ADT\nThe goal of this assignment is to sort a list of inputs both sorted and unsorted,\nlong and short and calculate number of comparisons and runtime. \n\n";
    
    readSmallInput(); //Populates small array from input files

    compare = 0; //Seats comapare equal to zero 
    auto start = high_resolution_clock::now();// Get starting timepoint 
    bubbleSort(small, smallSize); // call bubble sort
    auto stop = high_resolution_clock::now();// Get ending timepoint 
    auto duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto bubTimeSU = duration.count(); // save elapsed runtime
    bubCompSU = compare; // save total comparisons 
    cout << "Time taken by small set unsorted bubble sort function: "<< bubTimeSU << " microseconds" << endl;
    cout << "Number of comparisons made: " << bubCompSU << endl << endl;
    
    
    compare = 0;//Seats comapare equal to zero 
    start = high_resolution_clock::now();// Get starting timepoint
    bubbleSort(small, smallSize); // call bubble sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto bubTimeSS = duration.count(); // save elapsed runtime
    bubCompSS = compare;
    cout << "Time taken by small set sorted bubble sort function: " << bubTimeSS << " microseconds" << endl;
    cout << "Number of comparisons made: " << bubCompSS << endl << endl;

    readSmallInput(); //Reopulates small array from input files with unsorted list

    compare = 0;//Seats comapare equal to zero 
    start = high_resolution_clock::now();// Get starting timepoint
    quickSort(small, 0, smallSize-1); // call quick sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto quickTimeSU = duration.count(); // save elapsed runtime
    quickCompSU = compare; // save total comparisons 
    cout << "Time taken by small set unsorted quick sort function: " << quickTimeSU << " microseconds" << endl;
    cout << "Number of comparisons made: " << quickCompSU << endl << endl;
    
    compare = 0;//Seats comapare equal to zero 
    start = high_resolution_clock::now();// Get starting timepoint
    quickSort(small, 0, smallSize-1); // call quick sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto quickTimeSS = duration.count(); // save elapsed runtime
    quickCompSS = compare; // save total comparisons 
    cout << "Time taken by small set sorted quick sort function: " << quickTimeSS << " microseconds" << endl;
    cout << "Number of comparisons made: " << quickCompSS << endl << endl;

    readLargeInput(); //Populates large array from input files
    
    compare = 0;//Seats comapare equal to zero 
    start = high_resolution_clock::now();// Get starting timepoint 
    bubbleSort(large, largeSize); // call bubble sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto bubTimeLU = duration.count(); // save elapsed runtime
    bubCompLU = compare; // save total comparisons 
    cout << "Time taken by large set unsorted bubble sort function: " << bubTimeLU << " microseconds" << endl;
    cout << "Number of comparisons made: " << bubCompLU << endl << endl;

    compare = 0;//Seats comapare equal to zero 
    start = high_resolution_clock::now();// Get starting timepoint
    bubbleSort(large, largeSize); // call bubble sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto bubTimeLS = duration.count(); // save elapsed runtime
    bubCompLS = compare; // save total comparisons 
    cout << "Time taken by large set sorted bubble sort function: " << bubTimeLS << " microseconds" << endl;
    cout << "Number of comparisons made: " << bubCompLS << endl << endl;

    
    readLargeInput(); //Reopulates large array from input files with unsorted list
    
    compare = 0;
    start = high_resolution_clock::now();// Get starting timepoint
    quickSort(large, 1, largeSize-1); // call quick sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto quickTimeLU = duration.count(); // save elapsed runtime
    quickCompLU = compare; // save total comparisons 
    cout << "Time taken by large set unsorted quick sort function: " << quickTimeLU << " microseconds" << endl;
    cout << "Number of comparisons made: " << quickCompLU << endl << endl;
    
    compare = 0;
    start = high_resolution_clock::now();// Get starting timepoint
    quickSort(large, 1, largeSize - 1); // call quick sort
    stop = high_resolution_clock::now();// Get ending timepoint 
    duration = duration_cast<microseconds>(stop - start);// Get duration. 
    auto quickTimeLS = duration.count(); // save elapsed runtime
    quickCompLS = compare; // save total comparisons 
    cout << "Time taken by large set sorted quick sort function: " << quickTimeLS << " microseconds" << endl;
    cout << "Number of comparisons made: " << quickCompLS << endl << endl;

    
    smallOutputfile.open("Small_Sorted_Output.txt"); // open fle
   
    smallOutputfile << "The sorted list is :\n"; //Saves sorted list to file
    for (int i = 0; i < smallSize; i++)
    {
        smallOutputfile << small[i] << endl;
    }

    //Saves small list comparisons and runtimes for bubble sort and quick sort to file 
    smallOutputfile << "The bubble sort of the unsorted small set took " << bubTimeSU << " microseconds and "<< bubCompSU << " comparisons." << endl;
    smallOutputfile << "The bubble sort of the unsorted small set took " << bubTimeSS << " microseconds and " << bubCompSS << " comparisons.\n" << endl;
   
    smallOutputfile << "The quick sort of the unsorted small set took " << quickTimeSU << " microseconds and " << quickCompSU << " comparisons." << endl;
    smallOutputfile << "The quick sort of the unsorted small set took " << quickTimeSS << " microseconds and " << quickCompSS << " comparisons." << endl;

    smallOutputfile.close(); //close file

   
    largeOutputfile.open("Large_Sorted_Output.txt");//open file

    largeOutputfile << "The sorted list is :\n"; //Saves sorrted list to file
    for (int i = 0; i < largeSize; i++)
    {
        largeOutputfile << large[i] << endl;
    }

    //Saves large list comparisons and runtimes for bubble sort and quick sort to file 
    largeOutputfile << "The bubble sort of the unsorted large set took " << bubTimeLU << " microseconds and " << bubCompLU << " comparisons." << endl;
    largeOutputfile << "The bubble sort of the unsorted large set took " << bubTimeLS << " microseconds and " << bubCompLS << " comparisons.\n" << endl;

    largeOutputfile << "The quick sort of the unsorted large set took " << quickTimeLU << " microseconds and " << quickCompLU << " comparisons." << endl;
    largeOutputfile << "The quick sort of the unsorted large set took " << quickTimeLS << " microseconds and " << quickCompLS << " comparisons." << endl;


    largeOutputfile.close();//close file

    cout << "\n\nPress ENTER key to exit program\n";
    //cin.get();

    return 0;
}