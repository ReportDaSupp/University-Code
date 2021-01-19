#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //Regular handlings for changing console color
}

int IntInput() //Function to return a integer cInput
{
	int iTemp; //Temporary variable
	while (true)
	{
		SetColor(13);
		iTemp = NULL; //Clearing variable
		cin >> iTemp; 
		if (!cin) //If cin doesnt have a valid value
		{
			SetColor(7);
			cout << "Invalid Input!"; 
			Sleep(300); //Wait 0.3 secs
			cin.clear(); //Clears recent Input
			cin.ignore(300,'\n');
			cout << endl << "Try Again: " << endl;
		}
		else
		{
			SetColor(7);
			break; //Exit loop when valid integer is inputted
		}
	}
	return(iTemp);
}

int IntNonZeroInput() //Function to return a Non-Zero integer cInput, same as above code but with commented change.
{
	int iTemp;
	while (true)
	{
		SetColor(13);
		iTemp = NULL;
		cin >> iTemp;
		if (!cin || iTemp == 0) //Added a Or function to disallow a zero value or a invalid character
		{
			SetColor(7);
			cout << "Invalid Input!";
			Sleep(300); //Wait 0.3 secs
			cin.clear(); //Clears recent Input
			cin.ignore(300, '\n');
			cout << endl << "Try Again: " << endl;
		}
		else
		{
			SetColor(7);
			break; //Exit loop when valid integer is inputted
		}
	}
	return(iTemp);
}

void Add(bool Add) //Addition and Subtraction Procedure
{
	system("cls"); //Clear Screen
	//Initializing Variables
	int iTotNums; //Total number of numbers
	int iTotal = 0; //Total after Addition
	int iNum; //Var for current NumberS
	if (Add) //Adding do this else do other
	{
		cout << "How Many Numbers Would You Like To Add: " << endl;
	}
	else //Other
	{
		cout << "How Many Numbers Would You Like To Subtract (the first is positive): " << endl;
	}
	iTotNums = IntInput(); //Call Validated Input
	cout << endl; 
	for (int i = 0; i < iTotNums; i++)
	{
		if (Add) //For Adding
		{
			cout << "Enter Number " << i + 1 << ": " << endl;
			iNum = IntInput();
			iTotal += iNum;
		}
		else //For Subtracting
		{
			if (i == 0) //First number Positive
			{ 
				cout << "Enter Number " << i + 1 << ": " << endl;
				iNum = IntInput();
				iTotal += iNum;
			}
			else //Rest of the numbers Negative
			{
				cout << "Enter Number " << i + 1 << ": " << endl;
				iNum = IntInput();
				iTotal -= iNum;
			}
		}
		
		
	}
	cout << "Total is: "<<iTotal << endl;
	_getch(); //Waits for user cInput
}

void Divide() //Procedure for Division
{
	system("cls");
	float fTotal; //Total as a float as division can create Decimal Numbers with Whole Integers
	int iNum1; 
	int iNum2;
	cout << "Welcome to Division " << endl;
	cout << "Enter Number 1: " << endl;
	iNum1 = IntInput(); //First number is any Integer as Zero can be divided by any Integer Zero times
	cout << "Enter Number 2: " << endl;
	iNum2 = IntNonZeroInput(); //Second number has to be any number other than Zero or can cause an error
	
	fTotal = (float)iNum1 / (float)iNum2;
	cout << "Total Is: " << fTotal << endl;
	_getch();
}

int Multipy() //Procedure for Multiplication
{
	system("cls"); //Clear Screen
	float fTotal;
	int iNum1;
	int iNum2;
	cout << "Welcome to The Area Calculator " << endl;
	cout << "Enter Width: " << endl;
	iNum1 = IntInput(); //Multiplication can be by Zero, so any Integer Value
	cout << "Enter Height: " << endl;
	iNum2 = IntInput();

	fTotal = (float)iNum1 * (float)iNum2; // Multiplication using floats so their is no loss of detail if a fractional number is used
	return(fTotal);
}

void RATriangle()
{
	char fSide = '0';
	system("cls");
	cout << "Welcome to The Area Calculator " << endl << endl;

	for (int i = 1; i <= 5; ++i) //Drawing a Right-Angled Triangle out of Asterisks, with labels
	{
		if (i != 3) { cout << "  "; }

		for (int j = 1; j <= i; ++j)
		{
			if (i == 3 && j == 1) { cout << "A "; } //Adding The A On The Left after the 3rd line in the first place

			cout << "* ";

			if (j == 3 && i == 3) { cout << "C "; } //Adding the C On The Right side
		}
		cout << endl;
	}
	cout << "     B";
	cout << endl;

	cout << "Enter Missing Side (A, B, C)" << endl;
	do 
	{
		fSide = toupper(_getch()); //Takes cInput Char to upper case
		if (fSide == 'A' || fSide == 'B' || fSide == 'C') //Checks if Input is A, B, C. If not it takes a new cInput
		{
			cout << endl;
			break;
		}

	} while (1); //Constant loop till conditions are met

	int iSideA = 0;
	int iSideB = 0;
	int iSideC = 0;
	float fMissingSide = 0;

	switch (fSide)
	{
	case 'A': //First case if 'A' is Missing
	
		cout << "Enter Length of Side B: " << endl;
		iSideB = IntNonZeroInput(); //Cant be zero so takes non zero cInput
		cout << "Enter Length of Side C: " << endl;
		iSideC = IntNonZeroInput();
		fMissingSide = sqrt ((float)(iSideC * iSideC) - (float)(iSideB * iSideB)); //square root needs positive int other than zero, however in this case as it is being squared first any non zero int is fine
		cout << "The Length of Side A is: " << fMissingSide;
		_getch(); //Get Character
		break;
	
	case 'B': //Same as before but for B
	
		cout << "Enter Length of Side A: " << endl;
		iSideA = IntNonZeroInput();
		cout << "Enter Length of Side C: " << endl;
		iSideC = IntNonZeroInput();
		fMissingSide = sqrt ((float)(iSideC * iSideC) - (float)(iSideA * iSideA)); //square root needs positive int other than zero, however in this case as it is being squared first any non zero int is fine
		cout << "The Length of Side B is: " << fMissingSide;
		_getch(); //Get Character
		break;
	

	case 'C'://Same as before but for C
	
		cout << "Enter Length of Side A: " << endl;
		iSideA = IntNonZeroInput();
		cout << "Enter Length of Side B: " << endl;
		iSideB = IntNonZeroInput();
		fMissingSide = sqrt ((float)(iSideA * iSideA) + (float)(iSideB * iSideB)); //square root needs positive int other than zero, however in this case as it is being squared first any non zero int is fine
		cout << "The Length of Side C is: " << fMissingSide;
		_getch(); //Get Character
		break;
	
	}
}

void StatisticalCalculator()
{
	system("cls");
	float fStanDev1 = 0; //Standard Deviation Pre Calculation
	float fStanDev = 0; //Final Standard Deviation
	int iTotNum; //Total Number of Numbers
	float fMean = 0; //Calculate Mean

	cout << "How Many Numbers in Array: ";
	iTotNum = IntNonZeroInput(); // Input Length of Array

	iTotNum = sqrt((iTotNum) * (iTotNum));  // Converts Input to a Positive Int in case of a negative inputted

	int* aNums = new int[iTotNum]; //Array Of Numbers 1d
	int temp;

	cout << endl;
	cout << "Enter " << iTotNum << " Random Integers" << endl;

	for (int count = 0; count < iTotNum; count++) //For Loop for Input of Numbers to Array
	{

		cout << endl << "Enter Num " << count + 1 << ": ";
		temp = IntInput();
		aNums[count] = temp;

	}

	for (int x = 0; x < iTotNum - 1; x++) { //Simple Bubble Sort Algorithm
		int z = 1; //Local Variable used as a Counter
		for (int i = 0; i < iTotNum - x - 1; i++) {
			if (aNums[i] > aNums[i + 1])  //If a[i] > a[i+1] then swap them, else next
			{
				int temp = aNums[i]; //Store as a Temp
				aNums[i] = aNums[i + 1]; //Set array[i] equal to array[i+1]
				aNums[i + 1] = temp; //Set array[i+1] equal to Temp therefore switching positions of i and i+1
			}
			else { z += 1; } //Add to Counter every time that a switch isnt made, if it runs the whole way through the list without swaps then
		}
		if (z == iTotNum) { break; } //Break
	}

	system("CLS");
	cout << "Bubble Sort Ordered Numbers: ";
	
	for (int i = 0; i < iTotNum; i++) //Print All Variables in the Display
	{
		if (i != iTotNum - 1) {cout << aNums[i] << ", ";} //Print a Comma Unless it is the last in the list

		fMean += aNums[i]; //Sum of All Integers in Array (used to calculate mean)

	}
	
	fMean = fMean / iTotNum;

	for (int i = 0; i < iTotNum; i++) //Calculating Standard Deviation
	{
		fStanDev1 += (aNums[i] - (fMean)) * (aNums[i] - (fMean));
	}

	fStanDev = sqrt(fStanDev1 / iTotNum); //Still Calculating Standard Deviation

	//Outputs, Already Described
	cout << endl << endl;
	cout << "The Smallest Number: " <<aNums[0]<<endl;
	cout << "The Largest Number: " << aNums[iTotNum - 1] << endl;
	cout << "The Range: " << aNums[iTotNum - 1] - aNums[0] << endl;
	cout << "The Mean Number: " << fMean << endl;
	cout << "The Standard Deviation: " << fStanDev << endl;
	cout << endl;

	_getch(); //Waits for user cInput
}

void QuadCalc()
{
	system("cls");

	float fLetterA;
	float fLetterB;
	float fLetterC;

	cout << "Welcome to the Quadratic Calculator" << endl;
	cout << "This Calculator Only Solves First Degree Equations" << endl;
	cout << "The Format is [(a)X^2 + (b)X + (c)]" << endl;
	cout << "An Example is 6x² + 11x - 35 = 0 or x² -x - 3 = 0 for testing purposes." << endl;
	cout << "Warning This Corretly Calculates Valid Quadratic Equations so Random Numbers Will More Than Likely Return Null" << endl; //Disclaimer
	cout << "Enter Variable a: " << endl;
	cin >> fLetterA;
	cout << "Enter Variable b: " << endl;
	cin >> fLetterB;
	cout << "Enter Variable c: " << endl;
	cin >> fLetterC;
	cout << "X is Either Equal To: " << ((-fLetterB) + sqrt((fLetterB * fLetterB) - 4 * fLetterA * fLetterC )) / (2 * fLetterA) << " Or " << ((-fLetterB) - sqrt((fLetterB * fLetterB) - 4 * fLetterA * fLetterC)) / (2 * fLetterA)<<endl; //Long Confusing Maths Equation that is used to find the X Value in a quadratic Equation.

	_getch(); //Waits for user cInput

}

void Title()
{
	string sCurrentTitle = "Calculator Main Menu"; //Menu Text

	system("cls");
	CONSOLE_SCREEN_BUFFER_INFO csbi; //Store Screen Information
	int iColumns, iRows; //Create Variables To Store The Data For The Columns and Rows

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	iColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1; //Calculate Columns
	iRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  //Calculate Rows

	for (int i = 0; i < iColumns-1; i++) { cout << "-"; } //Print Dashes (--------------------) Covering whole top row using iColumns from the stack overflow reference.
	cout << endl;
	SetColor(10);
	for (int i = 0; i < (iColumns - sCurrentTitle.length()) / 2; i++) { cout << " "; } //Print The Title In The Centre Of The Screen using Maths to estimate
	cout << sCurrentTitle << endl;
	SetColor(7);
	for (int i = 0; i < iColumns-1; i++) { cout << "-"; } //Print Dashes
	cout << endl << endl;

}

void Options()
{

	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Divide" << endl;
	cout << "4. Area of Rectangle" << endl;
	cout << "5. Area of Triangle" << endl;
	cout << "6. Unknown Length of Right Angle Triangle" << endl;
	cout << "7. Statistical Calculator" << endl;
	cout << "8. Quadratic Calculator" << endl;
	cout << "9. Exit" << endl;

		char cExit;
		char cInput;
		float fTotal;
		cInput = _getch(); 
		
			switch (cInput) //Switch Statement for menu as it is more efficient than loads of if's
			{
			case '1': //Addition, in this case allows more than one number but can still do Add 2 numbers by choosing only 2 nums
				Add(true);
				break;
			case '2': //Subtraction, in this case allows more than one number but can still do subtract 2 numbers by choosing only 2 nums
				Add(false);
				break;
			case '3':
				Divide(); //Division
				break;
			case '4': //Area of Rectangle
				fTotal = Multipy();
				cout << "Area of Rectangle Is: " << fTotal << endl;
				_getch();
				break;
			case '5': //Area of Triangle
				fTotal = Multipy()/2;
				cout << "Area Of Triangle Is: " << fTotal << endl;
				_getch();
				break;
			case '6': //Pythagorean Theorem to Calculate missing fSide
				RATriangle();
				break;
			case '7': //Stat Calc From Previous Task
				StatisticalCalculator();
				break;
			case '8':
				QuadCalc();
				break;
			case '9': //Exit Script with confirmation
				cout << "Are You Sure You Want To Leave?"<<endl<<"Press 'Y' To Exit" << endl;
				cExit = toupper(_getch());
				if (cExit == 'Y') { exit(0); }
				break;
			default: //Clause for Invalid Input
				cout << "Invalid Input!" << endl;
				Sleep(400);
			}
		

}

int main()
{
	while(1) //Main Loop
	{
		Title();
		Options();
		system("cls");
	}
}
