#include "stdafx.h"
#include "iostream"
#include "string"
#include "RemoveSpaces.h"

using namespace std;

int main(int argc, char * argv[])
{
	string inputString(argv[1]);
	cout << RemoveExtraSpace(inputString) << endl;
	system("pause");
	return 0;
}

