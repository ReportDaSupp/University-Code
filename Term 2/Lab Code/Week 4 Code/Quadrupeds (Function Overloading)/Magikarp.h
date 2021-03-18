#pragma once
class Magikarp : public Fish
{
private:
	bool uselessFish;
public:
	Magikarp();
	void Attack();
	void Evolve();
	void run();
};

Magikarp::Magikarp()
{
	uselessFish = true;
}

void Magikarp::Evolve()
{
	uselessFish = false;
}

void Magikarp::Attack()
{
	cout << "Magikarp uses Splash" << endl << "Splash was Uneffective" << endl << endl;
}
void Magikarp::run()
{
	cout << "Failed to Run Away" << endl << endl;
}