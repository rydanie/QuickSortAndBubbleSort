// C++ program to generate random number 
#include<iostream>
#include<iomanip>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

int max = 0; //Max imum number of values in the list
int range = 0; //Sets the range of the genrated values from 0 to range
int value = 0; //Variable that stores random value
ofstream smallfile; //File stream for small output 
ofstream largefile; //File stream for large output


/*
	Runs the user interface which interacts with all ListADT methods.
	Outputs a text file of all program inputs and outputs when properly exitted
*/
int main()
{

	cout << "ENGR2400 Data Structures and Algorithms\nFall 2019\nRyley Danielson\nProgramming Assignment 4 - Buuble sort and Quick sort\nThe goal of this assignment is to generate data in another program and use the randomly gerated output from that program as input for this program.\nThis program will then sort the data using quick sort and buble sort and calculate the time taken to complete while also counting the number of comparisons.\nIt will then run through the sorted data and again calculate the number of comparisons and time to complete. \n\n";

	return 0;
}