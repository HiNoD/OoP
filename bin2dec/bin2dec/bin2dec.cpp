#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "string"
<<<<<<< HEAD
#include <math.h>
#include <bitset>
#include <stdlib.h>
=======
#include <math.h>  
>>>>>>> origin/master

using namespace std;

void PrintHelp()
{
<<<<<<< HEAD
	cout << "Example: bin2dec.exe 10101" << endl;
}

bool Check(const string inputNumber)
{
	int counter = 0;
	while (counter < inputNumber.size())
=======
	cout << "Example: bin2dec.exe 10101"<< endl;
}

void Check(string inputNumber, bool & error, int lengthOfString)
{
	int counter = 0;
	while (counter < lengthOfString && error != true)
>>>>>>> origin/master
	{
		if (inputNumber[counter] == '0' || inputNumber[counter] == '1')
		{
			counter++;
<<<<<<< HEAD
			return false;
		}
		else
		{
			return true;
=======
		}
		else
		{
			error = true;
>>>>>>> origin/master
		}
	}
}

<<<<<<< HEAD
int Converting(const string inputNumber)
{
	int buffer = 2, outputNumber = 0;
	for (int i = 0; i <= (inputNumber.size() - 1); i++)
	{
		if (i < (inputNumber.size() - 1))
		{
			buffer = buffer << (inputNumber.size()  - (i + 2));
		}
		else
		{
			buffer = 1;
		}
		if (inputNumber[i] == '0')
		{
			outputNumber += 0 * buffer;
			buffer = 2;
		}
		else
		{
			outputNumber += 1 * buffer;
			buffer = 2;
		}
	}
	return outputNumber;
=======
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
>>>>>>> origin/master
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
<<<<<<< HEAD
		string inputNumber = argv[1];

		if (Check(inputNumber))
		{
			if (inputNumber.size() == 0)
			{
				cout << "0" << endl;
			}
			else
			{
				cout << "Wrong number" << endl;
			}
		}
		else
		{
			cout << "Your number:" << Converting(inputNumber) << endl;
		}
	}
	return 0;
=======
		OperationRoom(argv);
	}
    return 0;
>>>>>>> origin/master
}

