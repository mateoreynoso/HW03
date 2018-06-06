//////////////////////////
// Mateo Reynoso
// Data Structures
// Homework 03
/////////////////////////////

// Written part
// 1. For each of the following errors, what kind of exception should be thrown ?
//	a.A subscript value that is equal to the number of elements in the array
//	b.An index for a string that is less than 0
//	c.A function return value that is too small to be represented
//	d.A function return value that is too large to be represented
//	e.An input operation that reads an invalid numeric string
//	f.Attempting to open an input stream whose associated disk file cannot be
//	found
//	g.Attempting to allocate storage for a dynamic array when there is not sufficient
//	memory available


#include <iostream>
#include <stdexcept>
#include "readint.h"
using namespace std;

int main()
{
	int low, high;
	try
	{
		cin.exceptions(ios::failbit || ios::badbit);
		cout << "Enter the range of values to read.\n";
		cout << "high: ";
		cin >> high;
		cout << "low: ";
		cin >> low;
	}

	catch (...)
	{
		std::cout << "Invalid input, try again. \n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		std::cout << "Input a number." << endl;
	}

	try
	{
		int number = read_int("Please enter a number within the range: ", low, high);
		cout << "You entered " << number << endl;
	}

	catch (invalid_argument &e) 
	{
		cerr << "Exception: You supplied an invalid argument for read_int!\n";
		cout << e.what() << endl;
	}

	

	system("pause");
}


