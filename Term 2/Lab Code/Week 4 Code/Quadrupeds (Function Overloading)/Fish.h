#pragma once
#include <iostream>
using namespace std;

class Fish
{
protected:
	string name;
public:
	void Swim();
	void Speak();
};

void Fish::Swim()
{
	cout << "Uses fins to paddle forward" << endl << endl;
}

void Fish::Speak()
{
	cout << "*Glug Glug" << endl << endl;
}