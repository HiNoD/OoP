#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "set"
#include "string"
#include "WorkingWithArray.h"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc < 1)
	{
		PrintHelp();
	}
	else
	{
		WorkingWithFile(argc, argv);
	}
	return 0;
}

