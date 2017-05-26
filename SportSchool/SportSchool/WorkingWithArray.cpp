#include "stdafx.h"
#include "fstream"
#include "WorkingWithArray.h"
#include "iostream"
#include "set"
#include "string"
#include "iterator"

using namespace std;

void WorkingWithFile(const int &argc,const char * argv[])
{
	set<string> listOfStudets;
	setlocale(LC_ALL, "rus");
	string buffer;

	for (int i = 1; i < (argc - 1); i++)
	{
		ifstream inputFile(argv[i]);
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
	string outputFileName = argv[argc - 1];
	ofstream outputFile(outputFileName);
	copy(listOfStudets.begin(), listOfStudets.end(), ostream_iterator<string>(outputFile, "\n"));
}

void PrintHelp()
{
	cout << "Example: SportSchool.exe input1.txt input2.txt" << endl;
}
