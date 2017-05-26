#include <boost/test/included/unit_test.hpp>
#include "stdafx.h"
#include "RemoveSpaces.h"

namespace
{
void VerifyStringWithOutExtraSpaces(const std::string &sourceStr, const std::string &expectedTrimmedString)
{
	BOOST_CHECK_EQUAL(sourceStr, expectedTrimmedString);
}
}

BOOST_AUTO_TEST_SUITE(VerifyStringWithOutExtraSpaces_function)
	BOOST_AUTO_TEST_CASE(must_conver_empty_string_to_empty_string)
	{
		VerifyStringWithOutExtraSpaces("", "");
	}
	BOOST_AUTO_TEST_CASE(removes_blanks_in_the_begining)
	{
		VerifyStringWithOutExtraSpaces("    word", "word");
	}
	BOOST_AUTO_TEST_CASE(removes_blanks_in_the_ending)
	{
		VerifyStringWithOutExtraSpaces("word    ", "word");
	}
	BOOST_AUTO_TEST_CASE(removes_blanks_in_the_middle)
	{
		VerifyStringWithOutExtraSpaces("word    word", "word word");
	}

BOOST_AUTO_TEST_SUITE_END()