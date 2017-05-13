#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "string"
#include <math.h>  

using namespace std;

void PrintHelp()
{
	cout << "Example: bin2dec.exe 10101"<< endl;
}

void Check(string inputNumber, bool & error, int lengthOfString)
{
	int counter = 0;
	while (counter < lengthOfString && error != true)
	{
		if (inputNumber[counter] == '0' || inputNumber[counter] == '1')
		{
			counter++;
		}
		else
		{
			error = true;
		}
	}
}

void Converting(const string & inputNumber, int lengthOfString, double & outputNumber)
{
	double gadfly = 0;
	for (int i = (lengthOfString - 1); i >= 0; i--)
	{
		gadfly = pow(2.0, (lengthOfString - (i + 1)));
		if (inputNumber[i] == '0')
		{
			outputNumber += 0 * gadfly;
		}
		else
		{
			outputNumber += 1 * gadfly;
		}
	}
}

void OperationRoom(char *argv[])
{
	string inputNumber = argv[1];
	bool error = false;
	int lengthOfString;
	double outputNumber = 0;
	lengthOfString = inputNumber.size();

	Check(inputNumber, error, lengthOfString);

	if (error == true)
	{
		cout << "Wrong number" << endl;
	}
	else
	{
		Converting(inputNumber, lengthOfString, outputNumber);
		cout << outputNumber << endl;
	}
}

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		PrintHelp();
	}
	else if (argc > 2)
	{
		cout << "Too many arguments" << endl;
	}
	else
	{
		OperationRoom(argv);
	}
    return 0;
}

