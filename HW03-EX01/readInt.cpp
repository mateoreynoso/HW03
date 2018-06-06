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
	bool inputState = false;
	std::cout << prompt;
	cin >> input;
	if (cin.fail())
	{
		std::cout << "Invalid input. \n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin >> input;
	}

	// Now checks the input is between the parameters
	bool correct = true;
	do
	{
		if (input < low || high < input)
		{
			std::cout << "The input is out of range.\n";
			std::cout << prompt;
			std::cin >> input;
		}
		else
			correct = false;
	} while (correct);

	return input;
}