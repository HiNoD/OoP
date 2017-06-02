#include "stdafx.h"
#include "fstream"
#include "WorkingWithSet.h"
#include "iostream"
#include "set"
#include "string"
#include "iterator"

using namespace std;

void WorkingWithSet(ifstream &inputFile, set<string> &listOfStudets)
{
	string buffer;

	if (!inputFile.is_open())
	{
		cout << "Happened error with opening file" << endl;
	}
	else
	{
		while (!inputFile.eof())
		{
			getline(inputFile, buffer);
			listOfStudets.insert(buffer);
		}
	}
}

void PrintHelp()
{
	cout << "Example: SportSchool.exe input1.txt input2.txt" << endl;
}
