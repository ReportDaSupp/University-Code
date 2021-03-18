#include <iostream>
#include <Windows.h>
#include "Fish.h"
#include "Magikarp.h"
#include "Gyarados.h"

using namespace std;

int main()
{
	unsigned int microseconds = 1000;
	Fish GenFishie;
	GenFishie.Speak();
	Sleep(microseconds);
	GenFishie.Swim();
	Sleep(microseconds);

	Magikarp Karpy;
	Karpy.Attack();
	Sleep(microseconds);
	Karpy.run();
	Sleep(microseconds);

	cout << "Evolving" << endl << endl;
	Sleep(2000);
	Gyarados* FIRST = new Gyarados();
	FIRST->Attack();
	Sleep(microseconds);
	FIRST->run();
	Sleep(microseconds);
	FIRST->Speak();
	Sleep(microseconds);

	cout << "De-Evolving" << endl << endl;
	Sleep(2000);
	delete FIRST;
	Magikarp* FIRST = new Magikarp();
	FIRST->Evolve();
	Sleep(microseconds);
	FIRST->Attack();
	Sleep(microseconds);
	FIRST->Attack();
	Sleep(microseconds);
	FIRST->Speak();
	Sleep(microseconds);
}