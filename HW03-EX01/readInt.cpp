#include "readInt.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int read_int(const string &prompt, int low, int high)

{
	// First checks the arguments
	if (low >= high)
	{
		throw invalid_argument("The smallest acceptable number cannot be higher that the largest acceptable integer.");
	}

	// Next asks the user for the input
	int input;
	
	try
	{
		cin.exceptions(ios::failbit | ios::badbit);
		std::cout << prompt;
		cin >> input;
	}

	// Makes sure the input is an int
	catch (ios_base::failure &ex)
	{
		std::cout << "Invalid input, try again. \n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		std::cout << "Input a number." << endl;
	}

	// Now checks the input is between the parameters
	bool correct = false;
	do
	{
		if (input < low || high < input)
		{
			std::cout << "The input is out of range.\n";
			std::cout << prompt;
			std::cin >> input;
		}
		else
			correct = true;
	} while (correct);

	return input;
}