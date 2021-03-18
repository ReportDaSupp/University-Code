#ifdef QUADRUPED_H
#define QUADRUPED_H

#include <iostream>
#include "leg.h"

using namespace std;

class Quadruped
{
protected:
	static const int kiNoLegs = 4;
	leg legs[kiNoLegs];
public:
	void raiseleg(int legIndex) 
	{
		if (legIndex > 0 && legIndex < kiNoLegs)
		{
			legs[legIndex].raise();
		}
	}
	void lowerLeg(int legIndex)
	{
		if (legIndex > 0 && legIndex < kiNoLegs)
		{
			legs[legIndex].lower();
		}
	}
	virtual void speak() = 0;
};
#endif