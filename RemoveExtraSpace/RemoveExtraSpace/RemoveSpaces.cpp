#include "stdafx.h"
#include "RemoveSpaces.h"
#include "iostream"
#include "string"

using namespace std;

string RemoveExtraSpace(const string & inputString)
{
	string duplicateString = inputString;
	for (int i = 0; i < duplicateString.size();)
	{
		if (duplicateString[i] == ' ' && duplicateString[i + 1] == ' ')
		{
			duplicateString.erase(i, 1);
		}
		else
		{
			i++;
		}
	}
	if (duplicateString[0] == ' ')
	{
		duplicateString.erase(0, 1);
	}
	if (duplicateString[duplicateString.size() - 1] == ' ')
	{
		duplicateString.erase(duplicateString.size() - 1, 1);
	}
	return duplicateString;
}
