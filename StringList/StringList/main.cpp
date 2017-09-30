#include "stdafx.h"
#include <list>
#include <iostream>
#include <string>
#include "StringList.h"


using namespace std;

int main()
{
	{
		cout << "123" << endl;
		CMyList<std::string> lst_;
		lst_.Append("1");
		lst_.Append("2");
		lst_.Append("3");
		lst_.Append("4");
		lst_.Append("5");
		for (auto it = lst_.begin(); it != lst_.end(); ++it)
		{
			cout << *it << endl;
		}
		cout << "123" << endl;

		CMyList<std::string> lst2;
		lst2 = lst_;
	}
	{
		CMyList<std::string> lst_;
		lst_.AddToFront("1");
		lst_.AddToFront("2");
		lst_.AddToFront("3");
		lst_.AddToFront("4");
		lst_.AddToFront("5");
		for (auto it = lst_.begin(); it != lst_.end(); ++it)
		{
			cout << *it << endl;
		}
		for (auto it = lst_.rbegin(); it != lst_.rend(); ++it)
		{
			cout << *it << " Range-based-for" << endl;
		}
	}

	{
		CMyList<double> lst;
		auto end = lst.begin();
		auto end1 = lst.end();
	}

	CMyList<std::string> lst1;
	lst1.Append("1");
	lst1.Append("2");
	lst1.Append("3");
	
	CMyList<std::string> lst2;
	lst2 = lst1;


	struct MockObjWithDefaultExceptedConstruct
	{
		MockObjWithDefaultExceptedConstruct()
		{
			throw std::runtime_error("Test except");
		}
		MockObjWithDefaultExceptedConstruct(int num)
			: num(num)
		{
		};
		int num;
	};
	CMyList<MockObjWithDefaultExceptedConstruct> lst;

	struct Node
	{
		Node* m_node;
		std::function<void()> a = [this]() {m_node = m_node->m_node; };
	};

	return 0;
}

