#include "stdafx.h"
#include "iterator"
#include "algorithm"
#include "VectorProcessor.h"
#include <iostream>

using namespace std;

int main()
{
	vector<double>inputVector;
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(inputVector));
	if (!inputVector.empty())
	{
		double maxNumber = *max_element(inputVector.begin(), inputVector.end());
		if (maxNumber != 0)
		{
			DivisionNumbersOnMaxElement(inputVector);
			OutputFinalVector(inputVector);
		}
		else
		{
			cout << "Max number 0. We can't division your vector" << endl;
		}
	}
	return 0;
}

