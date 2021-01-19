#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

using namespace std;

void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //Regular handlings for changing console color
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

void DrawBoard(char cBoard[3][3])
{
	cout << cBoard[2][0] << " | " << cBoard[2][1] << " | " << cBoard[2][2] << endl;
	cout << "----------" << endl;
	cout << cBoard[1][0] << " | " << cBoard[1][1] << " | " << cBoard[1][2] << endl;
	cout << "----------" << endl;
	cout << cBoard[0][0] << " | " << cBoard[0][1] << " | " << cBoard[0][2] << endl << endl;
}

bool CheckNone(char cBoard[3][3]) 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cBoard[i][j] != 'X' && cBoard[i][j] != 'O') { return true; }
		}
	}
	return false;
}

bool CheckWin(char cBoard[3][3], char cWin)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Column
			if (i == 0 && cBoard[i][j] == cWin)
			{
				if (cBoard[i + 1][j] == cWin && cBoard[i + 2][j] == cWin)
				{
					return true;
				}
			}
			//Row
			if (j == 0 && cBoard[i][j] == cWin)
			{
				if (cBoard[i][j + 1] == cWin && cBoard[i][j + 2] == cWin)
				{
					return true;
				}
			}
			//Diagonal
			if (i == 0 && j == 0 && cBoard[i][j] == cWin)
			{
				if (cBoard[i + 1][j + 1] == cWin && cBoard[i + 2][j + 2] == cWin)
				{
					return true;
				}
			}
			if (i == 0 && j == 2 && cBoard[i][j] == cWin)
			{
				if (cBoard[i + 1][j - 1] == cWin && cBoard[i + 2][j - 2] == cWin)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int MiniMax(char cBoard[3][3], char cPlayer) 
{

	if (CheckWin(cBoard, 'X'))
	{ 
		return -1; 
	}

	if (CheckWin(cBoard, 'O'))
	{ 
		return 1; 
	}

	int iMoveA = -1;
	int iMoveB = -1;
	int iValue = -2;
	int iTempScore2;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; j++) 
		{
			if (cBoard[i][j] != 'X' && cBoard[i][j] != 'O')
			{
				char cTemp = cBoard[i][j];
				cBoard[i][j] = cPlayer;
				if (cPlayer == 'X') { cPlayer = 'O'; }
				else if (cPlayer == 'O') { cPlayer = 'X'; }
				iTempScore2 = -MiniMax(cBoard, cPlayer);
				if (iTempScore2 > iValue) 
				{
					iValue = iTempScore2;
					iMoveA = i;
					iMoveB = j;
				}
				cBoard[i][j] = cTemp;
			}
		}
	}
	if (iMoveA == -1 || iMoveB == -1) return 0;
	return iValue;
}

void ComputerMove(char cBoard[3][3], char cPlayer) 
{
	int iMove1 = -1;
	int iMove2 = -1;
	int iScore = -2;
	int iTempScore1;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (cBoard[i][j] != 'X' && cBoard[i][j] != 'O')
			{
				char cTemp = cBoard[i][j];
				cBoard[i][j] = 'O';
				iTempScore1 = -MiniMax(cBoard, 'X');
				cBoard[i][j] = cTemp;
				if (iTempScore1 > iScore) {
					iScore = iTempScore1;
					iMove1 = i;
					iMove2 = j;
				}
			}
		}
	}
	cBoard[iMove1][iMove2] = 'O';
}

void SoloGame()
{
	char aiTicTacToe[3][3];
	bool bGameComplete = false;
	int iCounter = 49;
	char cChoice = 49;
	char cInput = 0;
	bool bPlayer;
	bool bMoveCompleted = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			aiTicTacToe[i][j] = (char)iCounter;
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
			DrawBoard(aiTicTacToe);
			cout << "Which Square Would You Like Player 1?" << endl;
			cChoice = _getch();
			if (aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'X' || aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'O')
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
				aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] = 'X';
				if (CheckWin(aiTicTacToe, 'X'))
				{
					system("cls");
					Title("Tic Tac Toe Solo Vs Ai Game");
					DrawBoard(aiTicTacToe);
					cout << "Player 1 Wins!" << endl;
					bGameComplete = true;
				}
				bMoveCompleted = true;
			}
		}
		while (bPlayer == 1 && !bMoveCompleted)
		{
			
			ComputerMove(aiTicTacToe,'O');
			bMoveCompleted = true;
			if (CheckWin(aiTicTacToe, 'O'))
			{
				system("cls");
				Title("Tic Tac Toe Player Vs Player");
				DrawBoard(aiTicTacToe);
				cout << "Minimax Ai Wins!" << endl;
				bGameComplete = true;
			}
			
		}
		if (bMoveCompleted) { bPlayer = !bPlayer; bMoveCompleted = false; }
		if (!CheckNone(aiTicTacToe))
		{
			Title("Tic Tac Toe Solo Vs Ai Game");
			DrawBoard(aiTicTacToe);
			cout << "No Remaining Spaces - Draw!" << endl;
			bGameComplete = true;
		}
	}
	_getch();
}

void PlayerGame()
{
	char aiTicTacToe[3][3];
	bool bGameComplete = false;
	int iCounter = 49;
	char cChoice = 49;
	bool bPlayer = 0;
	bool bMoveCompleted = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			aiTicTacToe[i][j] = (char)iCounter;
			iCounter++;
		}
	}
	while (bGameComplete != true)
	{
		while (bPlayer == 0 && !bMoveCompleted)
		{
			Title("Tic Tac Toe Player Vs Player");
			DrawBoard(aiTicTacToe);
			cout << "Which Square Would You Like Player 1?" << endl;
			cChoice = _getch();
			if (aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'X' || aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'O')
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
				aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] = 'X';
				if (CheckWin(aiTicTacToe, 'X'))
				{
					system("cls");
					Title("Tic Tac Toe Player Vs Player");
					DrawBoard(aiTicTacToe);
					cout << "Player 1 Wins!" << endl;
					bGameComplete = true;
				}
				bMoveCompleted = true;
			}
		}
		while (bPlayer == 1 && !bMoveCompleted)
		{
			Title("Tic Tac Toe Player Vs Player");
			DrawBoard(aiTicTacToe);
			cout << "Which Square Would You Like Player 2?" << endl;
			cChoice = _getch();
			if (aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'X' || aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] == 'O')
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
				aiTicTacToe[((int)cChoice - 49) / 3][((int)cChoice - 49) % 3] = 'O';
				if (CheckWin(aiTicTacToe, 'O'))
				{
					system("cls");
					Title("Tic Tac Toe Player Vs Player");
					DrawBoard(aiTicTacToe);
					cout << "Player 2 Wins!" << endl;
					bGameComplete = true;
				}
				bMoveCompleted = true;
			}
		}
		if (bMoveCompleted) { bPlayer = !bPlayer; bMoveCompleted = false; }
		if (!CheckNone(aiTicTacToe) && !CheckWin(aiTicTacToe, 'X') && !CheckWin(aiTicTacToe, 'X'))
		{
			Title("Tic Tac Toe Player Vs Player");
			DrawBoard(aiTicTacToe);
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

void MultiplayerGame()
{

}

void AIGame() 
{
	string sWords[216]{ "abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom", "azure", "bagpipes", "bandwagon", "banjo", "bayou", "beekeeper", "bikini", "blitz", "blizzard", "boggle", "bookworm", "boxcar", "boxful", "buckaroo", "buffalo", "buffoon", "buxom", "buzzard", "buzzing", "buzzwords", "caliph", "cobweb", "cockiness", "croquet", "crypt", "curacao", "cycle", "daiquiri", "dirndl", "disavow", "dizzying", "duplex", "dwarves", "embezzle", "equip", "espionage", "euouae", "exodus", "faking", "fishhook", "fixable", "fjord", "flapjack", "flopping", "fluffiness", "flyby", "foxglove", "frazzled", "frizzled", "fuchsia", "funny", "gabby", "galaxy", "galvanize", "gazebo", "giaour", "gizmo", "glowworm", "glyph", "gnarly", "gnostic", "gossip", "grogginess", "haiku", "haphazard", "hyphen", "iatrogenic", "icebox", "injury", "ivory", "ivy", "jackpot", "jaundice", "jawbreaker", "jaywalk", "jazziest", "jazzy", "jelly", "jigsaw", "jinx", "jiujitsu", "jockey", "jogging", "joking", "jovial", "joyful", "juicy", "jukebox", "jumbo", "kayak", "kazoo", "keyhole", "khaki", "kilobyte", "kiosk", "kitsch", "kiwifruit", "klutz", "knapsack", "larynx", "lengths", "lucky", "luxury", "lymph", "marquis", "matrix", "megahertz", "microwave", "mnemonic", "mystify", "naphtha", "nightclub", "nowadays", "numbskull", "nymph", "onyx", "ovary", "oxidize", "oxygen", "pajama", "peekaboo", "phlegm", "pixel", "pizazz", "pneumonia", "polka", "pshaw", "psyche", "puppy", "puzzling", "quartz", "queue", "quips", "quixotic", "quiz", "quizzes", "quorum", "razzmatazz", "rhubarb", "rhythm", "rickshaw", "schnapps", "scratch", "shiv", "snazzy", "sphinx", "spritz", "squawk", "staff", "strength", "strengths", "stretch", "stronghold", "stymied", "subway", "swivel", "syndrome", "thriftless", "thumbscrew", "topaz", "transcript", "transgress", "transplant", "triphthong", "twelfth", "twelfths", "unknown", "unworthy", "unzip", "uptown", "vaporize", "vixen", "vodka", "voodoo", "vortex", "voyeurism", "walkway", "waltz", "wave", "wavy", "waxy", "wellspring", "wheezy", "whiskey", "whizzing", "whomever", "wimpy", "witchcraft", "wizard", "woozy", "wristwatch", "wyvern", "xylophone", "yachtsman", "yippee", "yoked", "youthful", "yummy", "zephyr2", "zigzag", "zigzagging", "zilch", "zipper", "zodiac", "zombie" };
	srand((unsigned) time(0));
	string sWord = sWords[rand() % 216];
	cout << "The Word is:"<<sWord << endl;
	_getch();
}

void Hangman()
{
	char cInput = 0;
	while (cInput != '1' && cInput != '2')
	{
		Title("Welcome To The Hangman Game!");
		cout << "Would You Like 1 or 2 Players?";
		cInput = _getch();

		switch (cInput)
		{
		case '1':
			cout << endl;
			AIGame();
			break;

		case '2':
			cout << endl;
			MultiplayerGame();
			break;
		}
	}
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
	case '1': //Addition, in this case allows more than one number but can still do Add 2 cBoard by choosing only 2 nums
		TicTacToe();
		break;
	case '2': //Subtraction, in this case allows more than one number but can still do subtract 2 cBoard by choosing only 2 nums
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


