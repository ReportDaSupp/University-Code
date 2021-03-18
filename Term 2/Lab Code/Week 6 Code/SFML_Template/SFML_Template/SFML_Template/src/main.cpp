#include <SFML/Graphics.hpp>
#include <iostream>
#include "conio.h"
#include <math.h>
#include <string>
#include <windows.h>

const int X = 10;
const int Y = 10;
const int PCode = int('p');

//using namespace std;
using namespace std;

struct player {

	char PlayerChar;
	int posx;
	int posy;
	int life;

};

void init(char world[][Y], struct player &Tank)
{
	int i, j;

	Tank.PlayerChar = char(PCode);
	Tank.posx = 10;
	Tank.posy = 5;
	Tank.life = 3;

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			world[i][j] = ' ';
		}
	}
	world[Tank.posx-1][Tank.posy-1] = Tank.PlayerChar;

}

void paint(char world[][Y])
{
	system("cls");
	int i, j;

	cout << endl << endl;

	for (i = 0; i < X; i++)
	{
		cout << "\t";
		for (j = 0; j < Y; j++)
		{
			cout << world[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "\t" << "Board" << endl;
}

void timer(char world[][Y], struct player Tank)
{
	char key;
	int step = 0;

	while (1)
	{
		paint(world);
		if (_kbhit())
		{
			key = _getch();
			cout << key;
		}

		Sleep(75);
	}
}

int main()
{
	char world[X][Y];
	struct player Tank;
	init(world, Tank);
	paint(world);
	timer(world, Tank);


	_getch();

	return 0;
}