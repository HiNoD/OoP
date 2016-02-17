#include "fstream"
#include "iostream"
#include "string"
#include "stdafx.h"

using namespace std;

void SearchTextAndOutput(std::string & string, const std::string & TextToSearch, int & numberString)
{
	int pos = string.find(TextToSearch);
	if (pos != (-1))
	{
		cout << numberString << endl;
		numberString++;
	}
	else
	{
		cout << "Text not found in that string" << endl;
		numberString++;
	}
}


void Dispatch(char *argv[])
{
	std::string InputFileName = argv[1];
	std::string TextToSearch = argv[2];

	ifstream inputFile(InputFileName);

	if (!inputFile.is_open())
	{
		cout << "Happened error with opening file" << endl;
	}

	int numberString = 1;

	while (!inputFile.eof())
	{
		std::string string;
		getline(inputFile, string);
		if (TextToSearch.length() > 0)
		{
			SearchTextAndOutput(string, TextToSearch, numberString);
		}
		else
		{
			cout << "The text you want to search is 0" << endl;
		}
	}
}

void PrintExample()
{
	cout << "Example:" << "OoP.exe" << "file name" << "text to search" << endl;
}

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		PrintExample();
	}
	else if (argc > 3)
	{
		cout << "Too many arguments" << endl;
		PrintExample();
	}
	else
	{
		Dispatch(argv);
	}
	return 0;
}

