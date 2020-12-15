#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int width;
int length;
float Twidth;
float Tlength;
int digits;

int countDigit(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return count;
}

int main()
{
	cin >> width;
	cin >> length;
	digits = countDigit(width);

	if (width < length) { Tlength = length / width; Twidth = 1; }
	else { Twidth = width / length; Tlength = 1; }

	for (int i = 0; i < round((Tlength * 30)+1); i++)
	{
		if (i % 2 == 0)
		{
			cout << "-";
		}
		else if (i % 2 == 1)
		{
			cout << " ";
		}
	}
	cout << endl;

	for (int i = 0; i < round(Twidth * 10); i++)
	{
		if (i == round((Twidth * 10) / 2))
		{
			cout << width;
			cout << " " << setfill(' ') << setw(round(Tlength * 30 - digits)) << "-" << endl;
		}
		else 
		{
			cout << "-" << setfill(' ') << setw(round(Tlength * 30)) << "-" << endl;
		}
	}

	for (int i = 0; i < round((Tlength * 30)+1); i++)
	{
		if (i == (Tlength * 15 - (digits / 2)))
		{
			cout << length;
			i += (digits-1);
		}
		else if (i%2 == 0)
		{
			cout << "-";
		}
		else
		{
			cout << " ";
		}
	
	}

	_getch();
}