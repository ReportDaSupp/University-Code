#include <iostream>
#include "test.h"

	Test::Test()
	{
		testInt = 0;
	}
	void Test::setint(int iValue)
	{
		testInt = iValue
	}
	int Test::getint()
	{
		return testInt;
	}

	using namespace std;

	int main()
	{
		Test test1;
		Test1.setint(30);
		cout << test1.getint();
		system("pause");
		return(0);
	}