#include <boost/test/included/unit_test.hpp>
#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		DivisionNumbersOnMaxElement(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}
	
	BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_no_positive_numbers)
	{
		vector<double> numbers = { -4, 0, -3 };
		auto copy(numbers); 
		DivisionNumbersOnMaxElement(numbers);
		BOOST_CHECK(numbers == copy);
	}

BOOST_AUTO_TEST_SUITE_END()