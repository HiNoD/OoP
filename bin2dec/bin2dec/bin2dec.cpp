#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "string"
#include <math.h>
#include <bitset>
#include <stdlib.h>

using namespace std;

void PrintHelp()
{
	cout << "Example: bin2dec.exe 10101" << endl;
}

bool Check(const string inputNumber)
{
	int counter = 0;
	while (counter < inputNumber.size())
	{
		if (inputNumber[counter] == '0' || inputNumber[counter] == '1')
		{
			counter++;
			return false;
		}
		else
		{
			return true;
		}
	}
}

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
}

