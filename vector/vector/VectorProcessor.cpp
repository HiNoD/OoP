#include "stdafx.h"
#include "VectorProcessor.h"
#include "vector"
#include "iostream"
#include "iomanip" 
#include "iterator"
#include "algorithm"
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;
using namespace boost::phoenix::placeholders;
using boost::transform;

void DivisionNumbersOnMaxElement(vector<double> &inputVector)
{
	double maxNumber = *max_element(inputVector.begin(), inputVector.end());
	boost::transform(inputVector, inputVector.begin(), arg1 / maxNumber);
}

void OutputFinalVector(vector<double> &inputVector)
{
	vector<double>::iterator it;
	cout << "Final vector:";
	for (it = inputVector.begin(); it < inputVector.end(); ++it)
	{
		cout << setprecision(3) << *it << ' ';
	}
	system("pause");
}