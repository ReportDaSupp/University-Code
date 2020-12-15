#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int iVanWeight;
int iMaxVanWeight;
int iVans = 1;
int iCParcel;
int iParcelCount = 0;
int iMaxParcel;

int Input() 
{
	int i; 
	while (true)
	{
		i = NULL; 
		cin >> i;
		if (!cin || (i > 120  && i != 999))
		{
			cout << "Invalid Input!";
			Sleep(300); 
			cin.clear(); 
			cin.ignore(300, '\n');
			cout << endl << "Try Again: " << endl;
		}
		else
		{
			break; 
		}
		if (i == ('999')) { break; }
	}
	return(i);
}

void parcels()
{
	while (1)
	{

		cout << "Enter The Current Parcel Weight: ";
		iCParcel = Input();
		if (iCParcel == 999) { break; }
		iParcelCount++;
		cout << "\n";
		if (iCParcel > iMaxParcel) { iMaxParcel = iCParcel; }
		if (iVanWeight + iCParcel > 750)
		{
			iVans++;
			if (iVanWeight > iMaxVanWeight)
			{
				iMaxVanWeight = iVanWeight;
			}
			iVanWeight = 0;
		}
		iVanWeight += iCParcel;
	}
}

int main()
{
    cout << "Welcome To Paul's Parcel Delivery Service\n";
    cout << "This Program is to track the weight of Parcels being loaded onto delivery vans\n";
	cout << "Type '999' to end Program\n";
	parcels();
	cout << "\n\n\nThere were " << iVans << " Vans\n";
	cout << "The Heaviest Van Weighed " << iMaxVanWeight << " Kg\n";
	cout << "The Heaviest Parcel Weighed " << iMaxParcel << " Kg\n";
	cout << "There were " << iParcelCount << " Parcels\n";
	char x = _getch();
}


