#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	Game game;

	while (game.getWindowIsOpen()) 
	{
		//Update
		game.Update();
		//Render
		game.Render();
	}
	
	return 0;
}

