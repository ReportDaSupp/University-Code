#ifndef TIMEOFDAY_H
#define TIMEOFDAY_H

#include <string>

using namespace std;

class TimeOfDay
{
private:
	int iHours;
	int iMinutes;
	int iSeconds;

public:
	TimeOfDay() { iHours = 0; iMinutes = 0; iSeconds = 0; }
	TimeOfDay(int iH, int iM, int iS) { iHours = iH; iMinutes = iM; iSeconds = iS; }
	void increment() { if (iSeconds < 59) { iSeconds++; } else if (iMinutes < 59) { iMinutes++; iSeconds = 0; } else if (iHours < 23) { iHours++; iMinutes = 0; iSeconds = 0; } else { iHours = 0; iMinutes = 0; iSeconds = 0; } }
	string toString() { return (to_string(iHours) + ":" + to_string(iMinutes) + ":" + to_string(iSeconds)); }
	bool isEqual(TimeOfDay other) { if (iHours == other.iHours && iMinutes == other.iMinutes && iSeconds == other.iSeconds) { return true; } else { return false; }; }
	bool isLessThan(TimeOfDay other) { if ((iHours < other.iHours) || (iHours == other.iHours && iMinutes < other.iMinutes) ||(iHours == other.iHours && iMinutes == other.iMinutes && iSeconds < other.iSeconds)) { return true; } else { return false; }; }
};

#endif
