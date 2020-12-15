#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <ctype.h>

using namespace std;

void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //Regular handlings for changing console color
}

bool InputString(string Word)
{
	for (int i = 0; i < Word.size(); i++){
		if ((int)(Word[i]) < 97 || (int)(Word[i]) > 122) { return false; }
		else { return true; }
	}
}

void Title(string sCurrentTitle)
{
	system("cls");
	CONSOLE_SCREEN_BUFFER_INFO csbi; //Store Screen Information
	int iColumns, iRows; //Create Variables To Store The Data For The Columns and Rows

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	iColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1; //Calculate Columns
	iRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  //Calculate Rows

	for (int i = 0; i < iColumns - 1; i++) { cout << "-"; } //Print Dashes (--------------------) Covering whole top row using iColumns from the stack overflow reference.
	cout << endl;
	SetColor(10);
	for (int i = 0; i < (iColumns - sCurrentTitle.length()) / 2; i++) { cout << " "; } //Print The Title In The Centre Of The Screen using Maths to estimate
	cout << sCurrentTitle << endl;
	SetColor(7);
	for (int i = 0; i < iColumns - 1; i++) { cout << "-"; } //Print Dashes
	cout << endl << endl;

}

void DrawBoard(char acBoard[3][3])
{
	//Draw The Board (Quite Self Explanatory)
	cout << acBoard[2][0] << " | " << acBoard[2][1] << " | " << acBoard[2][2] << endl; //Using [2][0] so that the array prints 789 /n 456 /n 123 that way it is the same formatting as the numpad
	cout << "----------" << endl;
	cout << acBoard[1][0] << " | " << acBoard[1][1] << " | " << acBoard[1][2] << endl;
	cout << "----------" << endl;
	cout << acBoard[0][0] << " | " << acBoard[0][1] << " | " << acBoard[0][2] << endl << endl;
}

bool CheckNone(char acBoard[3][3]) 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (acBoard[i][j] != 'X' && acBoard[i][j] != 'O') { return true; } //Loops through every piece in the board and checks if any places are not yet equal to a Piece, if so return true
		}
	}
	return false;
}

bool CheckWin(char acBoard[3][3], char cWin)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Column Win Condition
			if (i == 0 && acBoard[i][j] == cWin)
			{
				if (acBoard[i + 1][j] == cWin && acBoard[i + 2][j] == cWin) //if three consecutive i rows that are the same in the j value are equal to X or O's return True
				{
					return true;
				}
			}
			//Row Win Condition
			if (j == 0 && acBoard[i][j] == cWin)
			{
				if (acBoard[i][j + 1] == cWin && acBoard[i][j + 2] == cWin) //if three consecutive j columns that are the same in the i value are equal to X or O's return True
				{
					return true;
				}
			}
			//Diagonal Win Condition
			if (i == 0 && j == 0 && acBoard[i][j] == cWin) //if the X or O holds a the left to right diagonal
			{
				if (acBoard[i + 1][j + 1] == cWin && acBoard[i + 2][j + 2] == cWin)
				{
					return true;
				}
			}
			if (i == 0 && j == 2 && acBoard[i][j] == cWin) //if the X or O holds a the right to left diagonal
			{
				if (acBoard[i + 1][j - 1] == cWin && acBoard[i + 2][j - 2] == cWin)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int MiniMax(char acBoard[3][3], char cPlayer) 
{

	if (CheckWin(acBoard, 'X')) // if X Wins Return -1 saying Score Will Decrease
	{ 
		return -1; 
	}

	if (CheckWin(acBoard, 'O')) // if O Wins Return -1 saying Score Will Decrease
	{ 
		return 1; 
	}

	int iMoveA = -1;
	int iMoveB = -1;
	int iValue = -2;
	int iTempScore2 = 0;
	for (int i = 0; i < 3; ++i) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (acBoard[i][j] != 'X' && acBoard[i][j] != 'O') // loop through every Non X or O Assigned Locations on the board
			{
				char cTemp = acBoard[i][j]; // On The first avaliable square save the current char
				acBoard[i][j] = cPlayer; // Set The Current Char Equal To The Players Turn Who is Being Estimated For
				if (cPlayer == 'X') { cPlayer = 'O'; } // Swap The Current Player
				else if (cPlayer == 'O') { cPlayer = 'X'; } // Still Swapping Player
				iTempScore2 = -MiniMax(acBoard, cPlayer); // Recursively Calling The Function using The Other Player Char - Its Negative that way every Rotation you Get Good For O, Bad For X
					if (iTempScore2 > iValue)  // If It Returns A Strong Score Update Value
				{
					iValue = iTempScore2; // Value equals Score
					iMoveA = i; // Currently assigned Move = Current Grid Choice
					iMoveB = j; // Currently assigned Move = Current Grid Choice
				}
				acBoard[i][j] = cTemp;
			}
		}
	}
	if (iMoveA == -1 || iMoveB == -1) return 0;
	return iValue;
}

void ComputerMove(char acBoard[3][3], char cPlayer) 
{
	int iMove1 = -1; //Making The Initial Moves Equal To An Unassignable Value So I Can Tell If It Can Make A Move
	int iMove2 = -1;
	int iScore = -2; // Making The Initial Score Bad So It Will Choose To Make A Move Even If It Leads To Player Victory
	int iTempScore1;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (acBoard[i][j] != 'X' && acBoard[i][j] != 'O') //Checks if Location is Empty if so tests minimax and then 
			{
				char cTemp = acBoard[i][j]; 
				acBoard[i][j] = 'O';
				iTempScore1 = -MiniMax(acBoard, 'X');
				acBoard[i][j] = cTemp;
				if (iTempScore1 > iScore) {
					iScore = iTempScore1;
					iMove1 = i;
					iMove2 = j;
				}
			}
		}
	}
	acBoard[iMove1][iMove2] = 'O';
}

void SoloGame()
{
	char acTicTacToe[3][3];
	bool bGameComplete = false;
	int iCounter = 49; //Counter Starting At 49 As That Is The Correct Code For '1'
	char cChoice = 49;
	char cInput = 0;
	bool bPlayer;
	bool bMoveCompleted = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			acTicTacToe[i][j] = (char)iCounter;
			iCounter++;
		}
	}

	while (cInput != '1' && cInput != '2')
	{
		Title("Tic Tac Toe Solo Vs Ai Game");
		cout << "Would You Like To Play 1st or 2nd?";
		cInput = _getch();

		switch (cInput)
		{
		case '1':
			bPlayer = 0;
			break;

		case '2':
			bPlayer = 1;
			break;
		}
	}

	while (bGameComplete != true)
	{
		while (bPlayer == 0 && !bMoveCompleted)
		{
			Title("Tic Tac Toe Solo Vs Ai Game");
			DrawBoard(acTicTacToe);
			cout << "Which Square Would You Like Player 1?" << endl;
			cChoice = _getch();
			if (acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'X' || acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'O')
			{
				cout << "This Position Already Has A Tile" << endl;
				_getch();
			}
			else if (!((int)cChoice > 48 && (int)cChoice <= 57))
			{
				cout << "This Position Is Out Of Bounds" << endl;
				_getch();
			}
			else
			{
				acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] = 'X';
				if (CheckWin(acTicTacToe, 'X'))
				{
					system("cls");
					Title("Tic Tac Toe Solo Vs Ai Game");
					DrawBoard(acTicTacToe);
					cout << "Player 1 Wins!" << endl;
					bGameComplete = true;
				}
				bMoveCompleted = true;
			}
		}
		while (bPlayer == 1 && !bMoveCompleted)
		{
			
			ComputerMove(acTicTacToe,'O');
			bMoveCompleted = true;
			if (CheckWin(acTicTacToe, 'O'))
			{
				system("cls");
				Title("Tic Tac Toe Player Vs Player");
				DrawBoard(acTicTacToe);
				cout << "Minimax Ai Wins!" << endl;
				bGameComplete = true;
			}
			
		}
		if (bMoveCompleted) { bPlayer = !bPlayer; bMoveCompleted = false; }
		if (!CheckNone(acTicTacToe))
		{
			Title("Tic Tac Toe Solo Vs Ai Game");
			DrawBoard(acTicTacToe);
			cout << "No Remaining Spaces - Draw!" << endl;
			bGameComplete = true;
		}
	}
	_getch();
}

void PlayerGame()
{
	char acTicTacToe[3][3];
	bool bGameComplete = false;
	int iCounter = 49;
	char cChoice = 49;
	bool bPlayer = 0;
	bool bMoveCompleted = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			acTicTacToe[i][j] = (char)iCounter;
			iCounter++;
		}
	}
	while (bGameComplete != true)
	{
		while (bPlayer == 0 && !bMoveCompleted)
		{
			Title("Tic Tac Toe Player Vs Player");
			DrawBoard(acTicTacToe);
			cout << "Which Square Would You Like Player 1?" << endl;
			cChoice = _getch();
			if (acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'X' || acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'O')
			{
				cout << "This Position Already Has A Tile" << endl;
				_getch();
			}
			else if (!((int)cChoice > 48 && (int)cChoice <= 57))
			{
				cout << "This Position Is Out Of Bounds" << endl;
				_getch();
			}
			else
			{
				acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] = 'X';
				if (CheckWin(acTicTacToe, 'X'))
				{
					system("cls");
					Title("Tic Tac Toe Player Vs Player");
					DrawBoard(acTicTacToe);
					cout << "Player 1 Wins!" << endl;
					bGameComplete = true;
				}
				bMoveCompleted = true;
			}
		}
		while (bPlayer == 1 && !bMoveCompleted)
		{
			Title("Tic Tac Toe Player Vs Player");
			DrawBoard(acTicTacToe);
			cout << "Which Square Would You Like Player 2?" << endl;
			cChoice = _getch();
			if (acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'X' || acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'O')
			{
				cout << "This Position Already Has A Tile" << endl;
				_getch();
			}
			else if (!((int)cChoice > 48 && (int)cChoice <= 57))
			{
				cout << "This Position Is Out Of Bounds" << endl;
				_getch();
			}
			else
			{
				acTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] = 'O';
				if (CheckWin(acTicTacToe, 'O'))
				{
					system("cls");
					Title("Tic Tac Toe Player Vs Player");
					DrawBoard(acTicTacToe);
					cout << "Player 2 Wins!" << endl;
					bGameComplete = true;
				}
				bMoveCompleted = true;
			}
		}
		if (bMoveCompleted) { bPlayer = !bPlayer; bMoveCompleted = false; }
		if (!CheckNone(acTicTacToe) && !CheckWin(acTicTacToe, 'X') && !CheckWin(acTicTacToe, 'X'))
		{
			Title("Tic Tac Toe Player Vs Player");
			DrawBoard(acTicTacToe);
			cout << "No Remaining Spaces - Draw!" << endl;
			bGameComplete = true;
		}
	}
	_getch();
}

void TicTacToe() 
{
	char cInput = '0';
	while (cInput != '1' && cInput != '2')
	{
		Title("Welcome To The Tic Tac Toe Game!");
		cout << "Would You Like 1 or 2 Players?";
		cInput = _getch();

		switch (cInput)
		{
		case '1':
			cout << endl;
			SoloGame();
			break;

		case '2':
			cout << endl;
			PlayerGame();
			break;
		}

	}
}

bool CheckDone(string sCurrentWord) 
{
	for (int i = 0; i < sCurrentWord.length(); i++)
	{ 
		if (sCurrentWord[i] == '-')
		{
			return false;
		}
	}
	return true;
}

bool g_bCorrectGuess = false;

string FillWord(string sWord, string sCurrentWord, char cGuess)
{
	for (int i = 0; i < sWord.length(); i++)
	{
		if (sWord[i] == cGuess)
		{
			sCurrentWord[i] = cGuess;
			g_bCorrectGuess = true;
		}
	}
	return(sCurrentWord);
}

void DrawHangman(int iCurrentInt) 
{
	string Noose[10][6]
	{
	{ {	"               "},
	{	" |             "},
	{	" |             "},
	{	" |             "},
	{	" |             "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |             "},
	{	" |             "},
	{	" |             "},
	{	" |             "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |             "},
	{	" |             "},
	{	" |             "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         0   "},
	{	" |             "},
	{	" |             "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         0   "},
	{	" |         |   "},
	{	" |             "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         0   "},
	{	" |        /|   "},
	{	" |             "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         0/  "},
	{	" |        /|   "},
	{	" |             "},
	{	"_|_____________"} },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         0/  "},
	{	" |        /|   "},
	{	" |        /    "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         0/  "},
	{	" |        /|   "},
	{	" |        / |  "},
	{	"_|_____________"}, },
	{ {	" ___________   "},
	{	" |         |   "},
	{	" |         x/  "},
	{	" |        /|   "},
	{	" |        / |  "},
	{	"_|_____________"}, },
	};

	for (int i = 0; i < 6; i++) 
	{
		cout << Noose[iCurrentInt][i] << endl;
	}
}

void Hangman()
{
	char cGuess = '*';
	bool bGameWon = false;
	int Player;
	string sWord = "NULL";
	while (!(InputString(sWord)) || (sWord == "NULL"))
	{
		Title("Welcome To The Hangman Game!");
		cout << "Enter Own Word to Guess Here (enter n for a random word):";
		cin >> sWord;
		for (int i = 0; i < sWord.size(); i++)
		{
			sWord[i] = tolower(sWord[i]);
		}
	}
	if (sWord == "n")
	{
	string sWords[216]{ "abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom", "azure", "bagpipes", "bandwagon", "banjo", "bayou", "beekeeper", "bikini", "blitz", "blizzard", "boggle", "bookworm", "boxcar", "boxful", "buckaroo", "buffalo", "buffoon", "buxom", "buzzard", "buzzing", "buzzwords", "caliph", "cobweb", "cockiness", "croquet", "crypt", "curacao", "cycle", "daiquiri", "dirndl", "disavow", "dizzying", "duplex", "dwarves", "embezzle", "equip", "espionage", "euouae", "exodus", "faking", "fishhook", "fixable", "fjord", "flapjack", "flopping", "fluffiness", "flyby", "foxglove", "frazzled", "frizzled", "fuchsia", "funny", "gabby", "galaxy", "galvanize", "gazebo", "giaour", "gizmo", "glowworm", "glyph", "gnarly", "gnostic", "gossip", "grogginess", "haiku", "haphazard", "hyphen", "iatrogenic", "icebox", "injury", "ivory", "ivy", "jackpot", "jaundice", "jawbreaker", "jaywalk", "jazziest", "jazzy", "jelly", "jigsaw", "jinx", "jiujitsu", "jockey", "jogging", "joking", "jovial", "joyful", "juicy", "jukebox", "jumbo", "kayak", "kazoo", "keyhole", "khaki", "kilobyte", "kiosk", "kitsch", "kiwifruit", "klutz", "knapsack", "larynx", "lengths", "lucky", "luxury", "lymph", "marquis", "matrix", "megahertz", "microwave", "mnemonic", "mystify", "naphtha", "nightclub", "nowadays", "numbskull", "nymph", "onyx", "ovary", "oxidize", "oxygen", "pajama", "peekaboo", "phlegm", "pixel", "pizazz", "pneumonia", "polka", "pshaw", "psyche", "puppy", "puzzling", "quartz", "queue", "quips", "quixotic", "quiz", "quizzes", "quorum", "razzmatazz", "rhubarb", "rhythm", "rickshaw", "schnapps", "scratch", "shiv", "snazzy", "sphinx", "spritz", "squawk", "staff", "strength", "strengths", "stretch", "stronghold", "stymied", "subway", "swivel", "syndrome", "thriftless", "thumbscrew", "topaz", "transcript", "transgress", "transplant", "triphthong", "twelfth", "twelfths", "unknown", "unworthy", "unzip", "uptown", "vaporize", "vixen", "vodka", "voodoo", "vortex", "voyeurism", "walkway", "waltz", "wave", "wavy", "waxy", "wellspring", "wheezy", "whiskey", "whizzing", "whomever", "wimpy", "witchcraft", "wizard", "woozy", "wristwatch", "wyvern", "xylophone", "yachtsman", "yippee", "yoked", "youthful", "yummy", "zephyr2", "zigzag", "zigzagging", "zilch", "zipper", "zodiac", "zombie" };
	srand((unsigned)time(0));
	sWord = sWords[rand() % 216];
	}
	string sUsedLetters = "";
	string sCurrentWord;
	for (int i = 0; i < sWord.length(); i++)
	{
		sCurrentWord += '-';
	}
	cout << "The Word is: " << sWord << endl;
	int i = 1;
	while (i < 10)
	{
		if (CheckDone(sCurrentWord))
		{
			bGameWon = true;
			cout << endl <<"You Correctly Guessed " << sWord << endl;
			cout << "Congratulations!";
			break;
		}
		Title("Welcome To The Hangman Game!");
		cout << "There are " << 10 - i << " Guesses Remaining!" << endl;
		cout << "Currently Used Letters Are: " << sUsedLetters << endl;
		cout << "Current Word: " << sCurrentWord << endl;
		DrawHangman(i-1);
		cout << "Enter Guess Character: ";
		cGuess = '1';
		while (!isalpha(cGuess) || (sUsedLetters.find(cGuess)<sUsedLetters.length()))
		{
			cGuess = _getch();
			cGuess = tolower(cGuess);
		}
		sUsedLetters += (cGuess);
		sUsedLetters += ", ";
		sCurrentWord = FillWord(sWord, sCurrentWord, cGuess);
		if (g_bCorrectGuess == true) { g_bCorrectGuess = false; }
		else { i += 1; }
	}
	if (!bGameWon) 
	{
	Title("Welcome To The Hangman Game!");
	cout << "There are " << 0 << " Guesses Remaining!" << endl;
	cout << "Currently Used Letters Are: " << sUsedLetters << endl;
	cout << "Current Word: " << sCurrentWord << endl;
	DrawHangman(9);
	cout << endl << "Incorrect Guesses. The Correct Word Was " << sWord << endl;
	cout << "Better Luck Next Time!";
	}
	_getch();
}

void Options()
{
	cout << "1. TicTacToe" << endl;
	cout << "2. Hangman" << endl;
	cout << "3. Exit Program" << endl;

	char cExit;
	char cInput = 0;
	cInput = _getch();

	switch (cInput) //Switch Statement for menu as it is more efficient than loads of if's
	{
	case '1': //Addition, in this case allows more than one number but can still do Add 2 acBoard by choosing only 2 nums
		TicTacToe();
		break;
	case '2': //Subtraction, in this case allows more than one number but can still do subtract 2 acBoard by choosing only 2 nums
		Hangman();
		break;
	case '3': //Exit Script with confirmation
		cout << "Are You Sure You Want To Leave?" << endl << "Press 'Y' To Exit" << endl;
		cExit = toupper(_getch());
		if (cExit == 'Y') { exit(0); }
		break;
	default: //Clause for Invalid Input
		cout << "Invalid Input!" << endl;
		Sleep(400);
		break;
	}

}

int main()
{
    while (1) 
    {
		Title("Welcome To The Game Area!");
		Options();
    }
}


