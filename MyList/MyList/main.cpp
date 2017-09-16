// MyList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyList.h"

int main()
{
	MyList<int> lis;
	lis.PushBack(1);
	lis.PushBack(4);
	lis.PushFront(13);
	auto l = lis.begin();
	l++;
	lis.Insert(lis.begin(), 5);
    return 0;
}

