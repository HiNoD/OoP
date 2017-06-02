#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "WorkingWithSet.h"
#include "iostream"
#include "set"
#include "string"
#include "WorkingWithArray.h"
#include "iterator"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc < 1)
	if (argc < 2)
	{
		PrintHelp();
	}
	else
	{
		WorkingWithFile(argc, argv);
		set<string> listOfStudets;
		setlocale(LC_ALL, "rus");

		for (int i = 1; i < (argc - 1); i++)
		{
			ifstream inputFile(argv[i]);
			WorkingWithSet(inputFile, listOfStudets); 
		}

		string outputFileName = argv[argc - 1];
		ofstream outputFile(outputFileName);
		copy(listOfStudets.begin(), listOfStudets.end(), ostream_iterator<string>(outputFile, "\n"));
	}
	return 0;
}

