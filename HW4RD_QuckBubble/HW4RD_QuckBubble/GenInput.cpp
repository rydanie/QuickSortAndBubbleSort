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



// Driver program 
int main(void)
{
    /* 
     Creates a small sequence of random numbers with parameters set by the user
    */
    
    cout << "What is the max number of values less than or equal to 30: ";
    while (!(cin >> max) || (max > 30))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer less than or equal to 30: ";
    }
    cout << "What is the range of values: ";
    while (!(cin >> range))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer: ";
    }

    smallfile.open("Small_Random_Output.txt");

    for (int i = 0; i < max; i++)
    {
        value = rand() % range;
        smallfile << value << endl;
        cout << value << " ";
    }

    smallfile.close();

    /*
    Creates a large sequence of random numbers with parameters set by the user
   */

    cout << "\n\nWhat is the max number of values greater than or equal to 10,000: ";
    while (!(cin >> max) || (max < 10000))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer less than or equal to 30: ";
    }
    cout << "What is the range of values: ";
    while (!(cin >> range))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer: ";
    }

    largefile.open("Large_Random_Output.txt");

    for (int i = 0; i < max; i++)
    {
        value = rand() % range;
        largefile << value << endl;
        cout << value << " ";
    }

    largefile.close();

    cout << "\n\nPress ENTER key to exit program";
    cin.get();
    
    return 0;
}