#pragma once
class Gyarados : public Magikarp
{
public:
	void Attack();
	void run();
};

void Gyarados::Attack()
{
		cout << "Gyarados Uses Water Cannon" << endl << "Water Cannon Was Super Effective" << endl << endl;
}

void Gyarados::run()
{
		cout << "You Successfully Escaped" << endl << endl;
}