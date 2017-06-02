#include <boost/test/included/unit_test.hpp>
#include "stdafx.h"
#include "WorkingWithSet.h"

using namespace std;

namespace
{
	void SetsAreEqual(const set<string> sourceSet,const set<string> expectedSet)
	{
		BOOST_CHECK_EQUAL(sourceSet, expectedSet);
	}
}

BOOST_AUTO_TEST_SUITE(SetsAreEqual_function)

BOOST_AUTO_TEST_CASE(reading_empty_file)
{
	set<string> sourceSet;
	sourceSet.insert("");
	set<string> expectedSet;
	expectedSet.insert("");
	SetsAreEqual(sourceSet, expectedSet);
}

BOOST_AUTO_TEST_CASE(reading_only_one_name)
{
	set<string> sourceSet;
	sourceSet.insert("������ ���� ���������");	
	set<string> expectedSet;
	expectedSet.insert("������ ���� ���������");
	SetsAreEqual(sourceSet, expectedSet);
}

BOOST_AUTO_TEST_CASE(reading_only_one_name_in_two_files)
{
	set<string> sourceSet;
	sourceSet.insert("������ ���� ���������");
	sourceSet.insert("������ ���� ���������");
	set<string> expectedSet;
	expectedSet.insert("������ ���� ���������");
	SetsAreEqual(sourceSet, expectedSet);
}

BOOST_AUTO_TEST_SUITE_END()