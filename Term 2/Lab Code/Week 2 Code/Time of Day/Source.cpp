#include <iostream>

#include "TimeOfDay.h"

using namespace std;

int main()
{
	TimeOfDay();

	TimeOfDay midnight;
	TimeOfDay clockShopTime(13, 50, 30);

	if (midnight.isLessThan(clockShopTime))
	{
		cout << midnight.toString() << " is less than " << clockShopTime.toString() << endl;
	}
	else
	{
		cout << clockShopTime.toString() << " is less than " << midnight.toString() << endl;
	}
	system("pause");

	TimeOfDay tickingClock(0, 0, 1);
	while (!tickingClock.isEqual(midnight))
	{
		cout << tickingClock.toString() << endl;
		tickingClock.increment();
	}

	system("pause");
	return 0;
}
