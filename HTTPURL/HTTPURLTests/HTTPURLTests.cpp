#include "stdafx.h"
#include "../HTTPURL/HttpUrl.h"

BOOST_AUTO_TEST_SUITE(CHttpURL)

	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_string)

		BOOST_AUTO_TEST_CASE(if_scheme_incorrect_then_class_throw_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("htts://grouple.ru/news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(if_scheme_delimether_is_incorrect_then_class_throw_parsing_error_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https:/grouple.ru/news/elements"), CUrlParsingError);
		}

		BOOST_AUTO_TEST_CASE(if_domain_is_empty_then_class_throw_invalid_args_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https:///news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(if_domain_is_equal_space_then_class_throw_invalid_args_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https://     /news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(if_domain_contain_space_then_class_throw_invalid_args_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https://gro .kz/news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(if_scheme_correct_but_protocol_type_not_supported_class_throw_exception)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("ftp://grouple.ru/news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(if_document_is_empty_class_do_not_throw_exception)
		{
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://grouple.ru/"));
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://grouple.ru"));
		}

		BOOST_AUTO_TEST_CASE(if_document_is_empty_then_get_doc_returns_empty_doc_with_slash_ch)
		{
			CHttpUrl url1("https://grouple.ru/");
			BOOST_CHECK_EQUAL(url1.GetDocument(), "/");

			CHttpUrl url2("https://grouple.ru");
			BOOST_CHECK_EQUAL(url2.GetDocument(), "/");
		}

		BOOST_AUTO_TEST_CASE(if_url_contains_non_empty_document_get_doc_returns_him)
		{
			CHttpUrl url("http://grouple.ru/news/elements");
			BOOST_CHECK_EQUAL(url.GetDocument(), "/news/elements");
		}

		BOOST_AUTO_TEST_CASE(if_url_contains_port_then_port_will_be_different_from_standart)
		{
			CHttpUrl url("http://grouple.ru:14/news/elements");
			BOOST_CHECK_EQUAL(url.GetPort(), 14u);
		}

		BOOST_AUTO_TEST_CASE(port_may_be_final_element)
		{
			CHttpUrl url("http://grouple.ru:14");
			BOOST_CHECK_EQUAL(url.GetPort(), 14u);
		}

		BOOST_AUTO_TEST_CASE(if_there_is_a_colon_and_no_port_class_throw_excpt)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("http://grouple.ru:"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("http://grouple.ru:/news/elements"), CUrlParsingError);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_components)

		BOOST_AUTO_TEST_CASE(can_not_pass_an_invalid_domain_name)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("", "news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(can_not_pass_an_invalid_document)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("grouple.ru", "	"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(can_not_pass_an_domain_name_with_scheme_or_slash)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("https://grouple.ru", "news/elements"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(if_document_does_not_begin_with_slash_it_will_be_added)
		{
			CHttpUrl url1("grouple.ru", "");
			BOOST_CHECK_EQUAL(url1.GetDocument(), "/");

			CHttpUrl url2("grouple.ru", "news/elements");
			BOOST_CHECK_EQUAL(url2.GetDocument(), "/news/elements");
		}

		BOOST_AUTO_TEST_CASE(default_protocol_is_http_and_default_port_is_80)
		{
			CHttpUrl url("grouple.ru", "news/elements");
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTP);
			BOOST_CHECK_EQUAL(url.GetPort(), 80u);
		}

		BOOST_AUTO_TEST_CASE(can_explicitly_specify_the_protocol)
		{
			CHttpUrl url("grouple.ru", "news/elements", Protocol::HTTPS);
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK_EQUAL(url.GetPort(), 443u);
		}

		BOOST_AUTO_TEST_CASE(can_explicitly_specify_the_port_of_fourth_parameter)
		{
			CHttpUrl url("grouple.ru", "news/elements", Protocol::HTTPS, 05);
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK_EQUAL(url.GetPort(), 5u);
		}

	BOOST_AUTO_TEST_SUITE_END()

	struct initialize_url_
	{
		initialize_url_()
			: urlStr("https://grouple.ru/news/elements")
			, url(urlStr)
		{};

		std::string urlStr;
		CHttpUrl url;
	};

	BOOST_FIXTURE_TEST_SUITE(before_initialized_url, initialize_url_)

		BOOST_AUTO_TEST_CASE(can_get_the_protocol)
		{
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
		}

		BOOST_AUTO_TEST_CASE(as_our_protocol_has_equal_that_https_then_port_is_equal_443)
		{
			BOOST_CHECK_EQUAL(url.GetPort(), 443u);
		}

		BOOST_AUTO_TEST_CASE(can_get_the_domain_name)
		{
			BOOST_CHECK_EQUAL(url.GetDomain(), "grouple.ru");
		}

		BOOST_AUTO_TEST_CASE(can_get_the_document_with_slash_in_begin)
		{
			BOOST_CHECK_EQUAL(url.GetDocument(), "/news/elements");
		}

		BOOST_AUTO_TEST_CASE(can_get_the_url)
		{
			BOOST_CHECK_EQUAL(url.GetURL(), urlStr);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()