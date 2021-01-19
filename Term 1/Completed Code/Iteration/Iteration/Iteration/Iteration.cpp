#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	/*int iCounter;
	iCounter = 0;
	while (iCounter < 10)
	{
		cout << iCounter + 1 << endl;
		iCounter += 1;
	}*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*char iInput;
	do
	{
		cout << "Enter a Letter: ";
		cin >> iInput;
	} 
	while (iInput != 'x');
	cout << "You entered x, goodbye." << endl;*/
	
	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*for (int iCounter = 0; iCounter < 10; iCounter++)
	{
		cout << iCounter+1 << endl;
	}*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*cout << "i\tj" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << i << "\t" << j << endl;
		}
	}*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*string row1 = "  **  **  **  **  **  **";
	string row2 = "**  **  **  **  **  **  ";
	for (int i = 0; i < 4; i++)
	{
		cout << row1 << endl;
		cout << row2 << endl;
	}*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*string row1 = "  **  **  **  **  **  **";
	string row2 = "**  **  **  **  **  **  ";
	for (int i = 0; i < 8; i++)
	{
	if(i%2)
	{
		cout << row1 << endl;
		}
		else
		{
		cout << row2 << endl;
		}
	}*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*string sWhite = "  ";
	string sBlack = "**";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2)
			{
				if (j % 2)
				{
					cout << sWhite;
				}
				else
				{
					cout << sBlack;
				}
			}
			else
			{
				if (j % 2)
				{
					cout << sBlack ;
				}
				else
				{
					cout << sWhite ;
				}
			}
		}
		cout << endl;
	}*/
	
	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/
	
	/*char cInput= NULL;
	float fSum;
	float fNum;
	do 
	{
		cout << endl << endl << "Menu" << endl;
		cout << "a) Add 6 Numbers" << endl;
		cout << "b) Multiply 6 Numbers" << endl;
		cout << "c) Exit the Program" << endl;
		cin >> cInput;

		if (cInput == 'a')
		{
			fSum = 0;
			for (int i = 0; i < 6; i++)
			{
				cout << "Enter a number: ";
				cin >> fNum;
				fSum += fNum;
			}
			cout << "The Numbers sum to: " << fSum << endl;
		}
		else if (cInput == 'b')
		{
			fSum = 1;
			for (int i = 0; i < 6; i++)
			{
				cout << "Enter a Number: ";
				cin >> fNum;
				fSum *= fNum;
			}
			cout << "The Product of all 6 Numbers is: " << fSum << endl;
		}
	} while(cInput != 'c');*/

	/*for (int i = 0; i < 4; i++)
	{
		cout << endl;
	}*/

	/*string sActualPassword = "pr0gramm3r";
	string sEnteredPassword;
	bool bPasswordCorrect;
	bool bFinished;
	int iAttempts = 0;
	do
	{
		cout << "Enter Password: ";
		cin >> sEnteredPassword;
		iAttempts++;
		bPasswordCorrect = sEnteredPassword == sActualPassword;
		if (bPasswordCorrect)
		{
			bFinished = true;
		}
		else
		{
			bFinished = iAttempts >= 3;
		}
	} while (!bFinished);*/


int iLength; //Initialize Variables
int iWidth;
string iLines = "-----"; //String to store "Dashes"

do
{	
cout << "Enter Length of table: ";

	cin >> iLength; //Input Table Length
	while (cin.fail() || iLength <= 0 || iLength > 24)  //Check if a valid integer has been inputted
	{
		cout << "Bad Input" << endl;
		cin.clear();
		cin.ignore(256, '\n'); //Wipe recent cin Input
		cout << "Enter Length of table: "; //Repeat Question
		cin >> iLength; //Input Length
	}

	cout << "Enter Width of table: "; 

	cin >> iWidth; // Input Table Width
	while (cin.fail() || iWidth <= 0 || iWidth > 24) // Check for valid Integer
	{
		cout << "Bad Input" << endl;
		cin.clear();
		cin.ignore(256, '\n'); //Wipe Recent cin Input
		cout << "Enter Width of table: ";
		cin >> iWidth; //Input Width
	}
	
	for (int i = 1; i <= iLength; i++) //Initial Surrounding For Loop (looping as many times as the length)
	{
		for (int j = 1; j <= iWidth; j++) //Nested loop (Looping as many times as the width)
		{
			cout << iLines; //output predeclared string
		}
		cout << "-" << endl;
		for (int j = 1; j <= iWidth; j++)
		{
			cout << left;
			cout << ":" << setw(4) << i * j;
		}
		cout << ":" << endl;
	}
} 
while (iLength <= 0);

}