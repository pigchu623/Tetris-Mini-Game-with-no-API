
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

int arrayboard[10][10] = { { 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0 } }; //Array of the Tetris Board
const int arraysboardsize[4] = { 7,8,9,10 }; // Arracy of the Board Size
const int arrayblocks[19][5][5] = { { { 1,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,1,1,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,1,1,1 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,0,0,0,0 },{ 1,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 } },{ { 1,0,0,0,0 },{ 1,1,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 0,1,0,0,0 },{ 1,1,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,0,0,0 },{ 1,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,0,0,0 },{ 0,1,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,0,0,0,0 },{ 1,0,0,0,0 },{ 1,1,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 0,0,1,0,0 },{ 0,0,1,0,0 },{ 1,1,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,1,0,0 },{ 1,0,0,0,0 },{ 1,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,1,0,0 },{ 0,0,1,0,0 },{ 0,0,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,0,0,0 },{ 1,1,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },{ { 1,1,1,0,0 },{ 1,1,1,0,0 },{ 1,1,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } } };  // Array of the Different Blocks Type
const int arraysize[19][3] = { { 1,1,10 },{ 1,2,20 },{ 1,3,30 },{ 1,4,40 },{ 1,5,50 },{ 2,1,20 },{ 3,1,30 },{ 4,1,40 },{ 5,1,50 },{ 2,2,30 },{ 2,2,30 },{ 2,2,30 },{ 2,2,30 },{ 3,3,50 },{ 3,3,50 },{ 3,3,50 },{ 3,3,50 },{ 2,2,40 },{ 3,3,90 } }; //Array of Different Block Marks 
int arrayputtedbox[19] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // Array of each type of Blocks put in during one game

int ran = 0, timebome = 0, bomblong = 9; //ran = 0 = Player mode, 1= PC mode. timebome= Timebome mode. bomblong = turns needed to explo the bomb
int s = 3;
int p;
void startGame();                 //Avaliable Modes at the starting menu.
void Settings();
void Instructions();
void Credits();
int Exit();

void pcMode() {
	int set = 0;
	system("cls");

	cout << "Mode" << setw(3) << "" << "Description" << setw(3) << "" << "Switch" << endl;

	cout << "   0" << setw(3) << "" << "Player Mode" << setw(3) << "";
	switch (ran) {
	case 0: cout << "On"; break;
	case 1: cout << "Off";
	}
	cout << endl;

	cout << "   1" << setw(3) << "" << "PC Mode    " << setw(3) << "";
	switch (ran) {
	case 0: cout << "Off"; break;
	case 1: cout << "On";
	}
	cout << endl;
	cout << "Change mode:1(PC Mode) or 0(Player Mode)" << endl;
	do {
		cin >> ran;
		if (ran == 1) {
			cout << "PC Mode On." << endl;
			system("pause");
			return;
		}
		else if (ran == 0) {
			cout << "Player Mode On." << endl;
			system("pause");
			return;
		}
		else {
			cout << "Input error. Please enter again..." << endl;
			system("pause");
		}


	} while (ran < 0 || ran>1);
}

void changeBombTimer() {

	system("cls");
	cout << "The current bomb timer is " << bomblong << " moves" << endl;
	cout << "change bomb timer to: ";
	do {
		cin >> bomblong;
		if (bomblong < 6 || bomblong>9)
			cout << "Please only input 6-9" << endl;
	} while (bomblong < 6 || bomblong>9);

	cout << "The new bomb timer is " << bomblong << " moves" << endl;
	system("pause");
	return;
}
void changeBoardSize() {

	int boardSize;
	system("cls");
	cout << "The current board size is " << s + 7 << "x" << s + 7 << endl;
	cout << "change board size to: ";
	do {
		cin >> boardSize;
		switch (boardSize) {
		case 7: s = 0; break;
		case 8: s = 1; break;
		case 9: s = 2; break;
		case 10: s = 3; break;
		default:cout << "Please only input 7-10" << endl; break;
		}
	} while (boardSize < 7 || boardSize>10);

	system("cls");
	cout << "The new board size is " << boardSize << "x" << boardSize << endl;
	system("pause");
}

void timeBombMode() {

	system("cls");
	cout << "Mode" << setw(3) << "" << "Description    " << setw(3) << "" << "Switch" << endl;

	cout << "   0:" << setw(3) << "" << "Original mode  " << setw(3) << "";
	switch (timebome) {
	case 0: cout << "On"; break;
	case 1: cout << "Off";
	}
	cout << endl;

	cout << "   1:" << setw(3) << "" << "Timer bomb mode" << setw(3) << "";
	switch (timebome) {
	case 0: cout << "Off"; break;
	case 1: cout << "On";
	}
	cout << endl;
	cout << "Change mode:1(Timer bomb mode) or 0(Original mode)" << endl;
	do {
		cin >> timebome;
		if (timebome == 1) {
			cout << "Timer bomb mode On." << endl;
			system("pause");
			return;
		}
		else if (timebome == 0) {
			cout << "Original mode On." << endl;
			system("pause");
			return;
		}
		else {
			cout << "Input error. Please enter again..." << endl;
			system("pause");
		}


	} while (timebome < 0 || timebome>1);


}

class blocks {
public:
	blocks() {}

	blocks(int t) {
		type = t;
		row = arraysize[t][0];
		col = arraysize[t][1];
		marks = arraysize[t][2];
	}

	void settype(int t) {
		type = t;
		row = arraysize[t][0];
		col = arraysize[t][1];
		marks = arraysize[t][2];
	}

	void printblocks() {
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				if (arrayblocks[type][r][c] == 1)
					cout << right << setw(2) << "X";
				else cout << right << setw(2) << " ";
			}
			cout << endl;
		}
	}
	int getmarks() {
		return marks;
	}

	int gettype() {
		return type;
	}
	int getrow() {
		return row;
	}
	int getcol() {
		return col;
	}
private:
	int type, row, col, marks;
};

blocks arrayselect[3];

class board {
public:
	board(int s) {

		size = arraysboardsize[s];
		TotalScore = 0;
		puttingScore = 0;
		cleaningScore = 0;
		turn = 1;
	}

	void printboard() {                             //Printing the gameplay UI and the latest situation of the game board. Using double "For Loop" to print each item in the XY Array of the borad 
		system("cls");                              // if the item == 0, it prints out ' ', if == 1, it prints out 'X'.  If >1, it means it is a Timer Bomb. It
		cout << setw(3) << " ";                     // If >1, it means it is a Timer Bomb. It shows its counting time.
		for (int i = 0; i < size; i++) {
			cout << setw(2) << i;
		}
		cout << setw(2) << " ";
		cout << endl;
		cout << setw(3) << "+";
		for (int i = 0; i < size; i++) {
			cout << setw(2) << "--";
		}
		cout << setw(2) << "-+" << endl;
		for (int r = 0; r < size; r++) {
			cout << setw(2) << (char)('A' + r) << "|";
			for (int c = 0; c < size; c++) {
				if (arrayboard[r][c] == 1)cout << setw(2) << "X";
				else if (arrayboard[r][c] > 1) {
					cout << setw(2) << arrayboard[r][c] - 2;
				}

				else cout << setw(2) << " ";
			}
			cout << setw(2) << "|";
			cout << endl;
		}
		cout << setw(3) << "+";
		for (int i = 0; i < size; i++) {
			cout << setw(2) << "--";
		}
		cout << setw(2) << "-+" << endl;
	}

	void firstTurn() {                                //Randomly Generate the first 3 Blocks that let the player to choose.

		arrayselect[0].settype(rand() % 19);
		arrayselect[1].settype(rand() % 19);
		arrayselect[2].settype(rand() % 19);

	}
	int loopturn() {                                  // Function for printing out those 3 selectable blocks and waiting for the player to input choosing which one.
		char arrayselection[5];
		int  t, quit = 0;

		cout << "Selection: 0" << endl;
		arrayselect[0].printblocks();
		cout << endl;
		cout << "Selection: 1" << endl;
		arrayselect[1].printblocks();
		cout << endl;
		cout << "Selection: 2" << endl;
		arrayselect[2].printblocks();
		cout << endl;
		cout << "Please select a block 0-2: ";
		if (ran == 0) {
			do {

				cin >> arrayselection;

				if (strcmp(arrayselection, "Quit") == 0)
					quit = Quit();
				else if (strcmp(arrayselection, "quit") == 0)
					quit = Quit();
				else if (strcmp(arrayselection, "Help") == 0)
					helpputting();
				else if (strcmp(arrayselection, "help") == 0)
					helpputting();
				else if (arrayselection[0] != 48 && arrayselection[0] != 49 && arrayselection[0] != 50)
					cout << "Input error, please input again...\n";
				if (quit == 1) {
					return t = 19;
				}
			} while ((quit == 0 && strcmp(arrayselection, "Quit") == 0) || (arrayselection[0] != 48 && arrayselection[0] != 49 && arrayselection[0] != 50));
		}
		else {
			arrayselection[0] = (rand() % 3 + '0');
			cout << arrayselection[0];
			system("pause");
		}
		p = arrayselection[0];
		p = p - 48;
		t = arrayselect[p].gettype();
		return t;
	}

	int overlap(int t, int x, int y) {                 // Function to Check is the selected block overlapping other blocks in the selected Coordinate.
		blocks p(t);
		int row, col;
		int s = 1;

		x = x - 48;
		if (t == 10)
			y = y - 66;
		else if (t == 14)
			y = y - 67;
		else
			y = y - 65;
		row = p.getrow();
		col = p.getcol();
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (arrayblocks[t][r][c] == 1) {
					if (arrayboard[y + r][x + c] > 0) {
						cout << "It's overlap..... place choose again." << endl;
						system("pause");
						s = 0;
						return s;
					}
				}
			}
		}
		return s;
	}

	int overlapver1(int t, int x, int y) {
		blocks p(t);
		int row, col;
		int s = 1;
		
		
		row = p.getrow();
		col = p.getcol();
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (arrayblocks[t][r][c] == 1) {
					if (arrayboard[y + r][x + c] > 0) {
						return s = 0;
					}
				}
			}
		}
		return s;
	}

	int offside(int t, int x, int y) {                 // Function to Check is the selected block offsided form the game board in the selected Coordinate.
		blocks p(t);
		int row, col;
		row = p.getrow();
		col = p.getcol();

		x = x - 48;
		if (t == 10)
			y = y - 66;
		else if (t == 14)
			y = y - 67;
		else
			y = y - 65;
		row = p.getrow();
		col = p.getcol();
		if (t == 10 && y == -1) {
			cout << "Out of bounds...place choose again." << endl;
			system("pause");
			return 0;
		}
		if (t == 14 && (y == -1 || y == -2)) {
			cout << "Out of bounds...place choose again." << endl;
			system("pause");
			return 0;
		}
		if ((x + col) <= arraysboardsize[s] && (y + row) <= arraysboardsize[s]) {
			return 1;
		}
		else {
			cout << "Out of bounds...place choose again." << endl;
			system("pause");
			return 0;
		}

	}

	void putting(int t, int x, int y) {                                      //Putting in the selected Block into assigned coordinate by changing the game board's array item. 
		blocks p(t);                        
		int row, col;
		int putmarks;
		putmarks = p.getmarks();
		row = p.getrow();
		col = p.getcol();

		x = x - 48;
		if (t == 10)
			y = y - 'A' - 1;
		else if (t == 14)
			y = y - 'A' - 2;
		else
			y = y - 65;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (arrayblocks[t][r][c] == 1)
					arrayboard[y + r][x + c] = arrayblocks[t][r][c];

			}
		}
		TotalScore += putmarks;
		puttingScore += putmarks;
		arrayputtedbox[t] += 1;

	}

	void helpputting() {
		int t;
		int row, col, o, ft, fc, fr;
		for (int i = 0; i <= 2; i++) {
			t = arrayselect[i].gettype();
			blocks p(t);
			row = p.getrow();
			col = p.getcol();
			for (int r = 0; r < size - row+1; r++) {
				for (int c = 0; c < size - col+1; c++) {
					o = overlapver1(t, c, r);
					if (o == 1) {
						cout << "You can put Block " << i << " into " << char(r+65) << c << endl;
						return;
					}
					 
				}
			}
		}
	}
	int Clean() {                                          //Clear the blocks that completed the whole row or col by changing the value of Game board array.
		int RolToClean[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		int ColToClean[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		bool Cleaned = false;

		for (int r = 0; r < size; r++) {                   //Checking is the whole Rol has Blocks. If yes, mark down the Rol num
			int x = 0;
			for (int c = 0; c < size; c++) {
				if (arrayboard[r][c] > 0)
					x += 1;
				if (x == size) {
					RolToClean[r] = 1;
				
				}
			}
		}
		for (int c = 0; c < size; c++) {                  //Checking is the whole Col has Blocks. If yes, mark down the Col num
			int y = 0;
			for (int r = 0; r < size; r++) {
				if (arrayboard[r][c] > 0)
					y += 1;
				if (y == size) {
					ColToClean[c] = 1;
					
				}
			}
		}
		for (int i = 0; i < size; i++) {                 //Clean all the blocks in the Marked Rols and Cols.
			if (RolToClean[i] == 1) {
				for (int c = 0; c < size; c++) {
					arrayboard[i][c] = 0;
					Cleaned = true;
					}
			}
			if (ColToClean[i] == 1) {
				for (int r = 0; r < size; r++) {
				arrayboard[r][i] = 0;
				Cleaned = true;
				}
			}
		}

		if (Cleaned == true)
			return 1;
		else
			return 0;
	}

	void Counting() {                                   // Counting how many rows or col is removed in this move, then counting how much marks should add to the cleaning score.
		int count = 0;
		int cleanmarks;

		for (int r = 0; r < size; r++) {
			int x = 0;
			for (int c = 0; c < size; c++) {
				if (arrayboard[r][c] > 0)
					x += 1;
				if (x == size) {
					count += 1;
				}

			}
		}
		for (int c = 0; c < size; c++) {
			int y = 0;
			for (int r = 0; r < size; r++) {
				if (arrayboard[r][c] > 0)
					y += 1;
				if (y == size)
					count += 1;

			}
		}
		switch (count) {
		case 0:cleanmarks = 0; break;
		case 1:cleanmarks = 100; break;
		case 2:cleanmarks = 300; break;
		case 3:cleanmarks = 600; break;
		case 4:cleanmarks = 1000; break;
		case 5:cleanmarks = 1500; break;
		case 6:cleanmarks = 2100; break;
		}
		cout << "There are " << count << " line(s) complete!!\nTotalmarks +" << cleanmarks << "!!\n";
		TotalScore += cleanmarks;
		cleaningScore += cleanmarks;
		system("pause");
	}
	void numOfTurns() {
		turn += 1;
	}

	void setTimerbome() {                 //Timer Bomb Mode only. For every 5 turns, place a bomb into the game board randomly.
		int ran;
		if (turn % 5 == 0)
		{
			do {
				for (int r = 0; r < size; r++) {
					for (int c = 0; c < size; c++) {
						if (arrayboard[r][c] == 1) {
							ran = rand() % 3;
							if (ran == 0) {
								arrayboard[r][c] = bomblong + 2;
								return;
							}
						}
					}
				}
			} while (ran % 3 != 0);
		}
	}

	void changeTimeBome() {
		for (int r = 0; r < size; r++) {
			for (int c = 0; c < size; c++) {
				if (arrayboard[r][c] > 2) {
					arrayboard[r][c] -= 1;
				}
			}
		}
	}

	int bombgg() {                                      //Timer Bomb Mode Only. One of the Timer Bomb inside the game board count to zero. Game over.
		for (int r = 0; r < size; r++) {
			for (int c = 0; c < size; c++) {
				if (arrayboard[r][c] == 2) {
					printboard();
					cout << "Boom.....you are doomed!\nGame Over..." << endl;
					system("pause");
					return 1;
				}
			}
		}
		return 0;
	}
	int cantplacegg() {                                             // That selectable Blocks cannot fit in any place in the currnet game board. Game over.
		int t;
		int row, col, o;
		for (int i = 0; i <= 2; i++) {
			t = arrayselect[i].gettype();
			blocks p(t);
			row = p.getrow();
			col = p.getcol();
			for (int r = 0; r < size - row+1; r++) {
				for (int c = 0; c < size - col+1; c++) {
					o = overlapver1(t, c, r);
					if (o == 1)
						return 0;
				}
			}
		}
		cout << "your selections now are..." << endl;
		cout << "Selection: 0" << endl;
		arrayselect[0].printblocks();
		cout << endl;
		cout << "Selection: 1" << endl;
		arrayselect[1].printblocks();
		cout << endl;
		cout << "Selection: 2" << endl;
		arrayselect[2].printblocks();
		cout << endl;
		cout << "You cannot place your blocks anymore...\nGame Over...." << endl;
		system("pause");
		return 1;
	}

	int getTotalScore() {
		return TotalScore;
	}
	int getputtingScore() {
		return puttingScore;
	}
	int getcleaningScore() {
		return cleaningScore;
	}
	int getSize() {
		return size;
	}

	int Quit() {
		char q;
		do {
			cout << "You want to quit game? ";
			cin >> q;
			if (q == 'Y' || q == 'y') {
				return 1;
			}
			else if (q == 'n' || q == 'N') {
				return 0;
			}
			else
				cout << "What did you say?\n";
		} while (q != 'Y' || q != 'y' || q != 'n' || q != 'N');
	}
private:
	int size;
	int TotalScore, puttingScore, cleaningScore;
	int turn;
};


int main()
{
	int q = 0;
	cout << "+------------------------+\n|           *            |\n|           *            |\n|    Board and Blocks    |\n|           *            |\n|           *            |\n+------------------------+" << endl; //First UI shows up when the System start running 
	system("pause");


	int option_choice = 0;
	do
	{
		system("cls");
		cout << " Board and Blocks" << endl;            //shows the main menu of the system and avilible modes. input assigned number to continue
		cout << "****Game Menu****" << endl;
		cout << "[1] Start Game" << endl;
		cout << "[2] Settings" << endl;
		cout << "[3] Instructions" << endl;
		cout << "[4] Credits" << endl;
		cout << "[5] Exit" << endl;
		cout << "*****************" << endl;
		cout << "Option (1-5) :";
		cin >> option_choice;



		switch (option_choice) {
		case 1: startGame(); break;
		case 2: Settings(); break;
		case 3: Instructions(); break;
		case 4: Credits(); break;
		case 5: q = Exit(); break;

		default: cout << "Please enter option 1 - 5 only."; break;
		}
	} while (q != 1);

	cout << "End game.Thanks for playing! " << endl;

	return 0;

}


void startGame()
{
	system("cls");                       //first, clear the whole screen and reset all the marks .
	for (int i = 0; i < 19; i++) {
		arrayputtedbox[i] = 0;
	}
	
	board game(s);                        //creat a new object from class board, set the whole board clear.
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			arrayboard[r][c] = 0;
		}
	}
	char A[5];
	int x, y, t, o, l, row, col, turn = 1, quit = 0, size;         //set all the values as default
	bool NeedToClean = false;
	int failedCount = 0;
	srand(time(0));

	size = game.getSize();            //Get the size of the game 
	game.firstTurn();                 //Generate the first 3 blocks that let the player to choose


	do {
		if (ran != 0) {
		 failedCount = 0;
		}
			
		do {
			game.printboard();                                //Print out the current board situation
			cout << "Total Marks: " << game.getTotalScore() << " Turn: " << turn << endl << endl;
			t = game.loopturn();             // print out all the selectable blocks and wait the input of player. '0'-'2' pick the according block. 
			                                 // 'Quit' or 'quit' to shows the final score and quit game
			                                 // Others, Wrong input, stay in this do while loop
			if (t == 19) {
				system("cls");
				cout << "--------ScoreBoard--------" << endl;
				for (int i = 0; i < 19; i++) {
					cout << "type " << setw(2) << i << " put: " << arrayputtedbox[i] << " x " << arraysize[i][2] << endl;
				}
				cout << "Putting Score: " << game.getputtingScore() << endl;
				cout << "Cleaning Score: " << game.getcleaningScore() << endl;
				cout << "--------------------------" << endl;
				cout << "Your final total score is: " << game.getTotalScore() << endl;
				system("pause");
				return;
			}
			do {
				cout << "Where the block puts? ";
				if (ran == 0) {
					cin >> A;                          // Waiting the player input where should the block be placed.
					if (strcmp(A, "Quit") == 0)        //  And Check the input is within range or not.
						quit = game.Quit();            // if input 'Quit' or 'quit', the game is going to over and showing out the scores. 
					else if (strcmp(A, "quit") == 0)
						quit = game.Quit();
					else if (strcmp(A, "Help") == 0)
						game.helpputting();
					else if (strcmp(A, "help") == 0)
						game.helpputting();
					else if (A[0] <65 || A[0]>(65 + game.getSize()))
						cout << "input error, please input again..." << endl;
					else if (A[1]<'0' || A[1]>('0' + game.getSize()))
						cout << "input error, please input again..." << endl;
				}
				else {

					if (NeedToClean == false & turn != 0 & turn%3==0) 
						NeedToClean = true;
					if (NeedToClean == true) {
						
						int row, col;
						blocks p(t);
						row = p.getrow();
						col = p.getcol();
						int o = 0;
						for (int r = 0; r < size - row + 1; r++) {
							
							for (int c = 0; c < size - col + 1; c++) {
								o = game.overlapver1(t, c, r);
								if (o == 1) {
									if (t == 10)
										r = r + 1;
									else if (t == 14)
										r = r + 2;
									A[0] = r + 65;
									A[1] = c + '0';
									cout << A[0] << A[1] << endl;
									system("pause");
									break;
								}
							}

							if (o == 1) 
							break;
								
						}
					}
					else {
						A[0] = (rand() % size) + 65;       //(Need Correct) If PC Mode and first 5 turns, the sysytem will randomly input a Location that within the board size. (+65 is for tranfering to A in int)
						A[1] = (rand() % size) + '0';
						cout << A[0] << A[1] << endl;
						system("pause");
					}

				}
			} while (quit == 0 && strcmp(A, "Quit") == 0 || (A[0] <65 || A[0]>(65 + game.getSize())) || (A[1]<'0' || A[1]>('0' + game.getSize())));
			if (quit == 1) {
				system("cls");
				cout << "--------ScoreBoard--------" << endl;             //clear the whole screen. Print out the whole score calculation and final score
				for (int i = 0; i < 19; i++) {
					cout << "type " << setw(2) << i << " put: " << arrayputtedbox[i] << " x " << arraysize[i][2] << endl;
				}
				cout << "Putting Score: " << game.getputtingScore() << endl;
				cout << "Cleaning Score: " << game.getcleaningScore() << endl;
				cout << "--------------------------" << endl;
				cout << "Your final total score is: " << game.getTotalScore() << endl;
				system("pause");                         // press any key to go back to main menu
				return;
			}
			y = A[0];             //Transfering the player inputs to y and x and start checking will the selected block overlap the other or 
			x = A[1];             // offside from the board
			o = game.overlap(t, x, y);
			l = game.offside(t, x, y); 
			failedCount++;
			if (failedCount >= 3 && ran!= 0) {
				NeedToClean = true;
			}
		} while (o == 0 || l == 0);      
		game.putting(t, x, y);         //once both overlapping and offsiding are checked and both fine. The syste, will start putting the block
		game.printboard();            //into the board. then print the board again to its latest situation
		game.Counting();                //then counting score and turns
		if (game.Clean() == 1) {
			NeedToClean = false;
		}
		game.numOfTurns();
		turn += 1;
		game.changeTimeBome();
		if (timebome == 1) {            //If timer bomb mode is actived, Count down the bomb timer now.
			game.setTimerbome();
		}
		arrayselect[p].settype(rand() % 19);
	} while (game.bombgg() == 0 && game.cantplacegg() == 0);
	system("cls");                                       //once the board is not able to put in any blocks that the player current has 
	                                                     //or the timer bomb reaches 0, the system starts run the following

	cout << "--------ScoreBoard--------" << endl;         //Print out all the quantity of the blocks the player put in this run
	for (int i = 0; i < 19; i++) {                        //Then print out the Cleaning Score and Putting Score
		cout << "type " << setw(2) << i << " put: " << arrayputtedbox[i] << " x " << arraysize[i][2] << endl << endl;
	}
	cout << "Putting Score: " << game.getputtingScore() << endl << endl;
	cout << "Cleaning Score: " << game.getcleaningScore() << endl;
	cout << "--------------------------" << endl;
	cout << "Your final total score is: " << game.getTotalScore() << endl; //Print out the Total Final Score of this run
	system("pause");           // press any key to go back to main menu

	return;

}

void Settings()  //This mode able to select different game modes like let the pc runs the whole playthrough itself (PC Game Demo).
{                // Add a Timer Bomb into the game board (Timer Bomb Mode) Change the Board Size or Timer Bomb timer.
	system("cls");
	int setting_choice;
	do {
		system("cls");
		cout << "*** Settings Menu ***" << endl;
		cout << "[1] PC Game Demo" << endl;
		cout << "[2] Timer Bomb Mode" << endl;
		cout << "[3] Change Board Size" << endl;
		cout << "[4] Change Bomb Timer" << endl;
		cout << "[5] Return to Game Menu" << endl;
		cout << "*********************" << endl;
		cout << "Option (1 - 5): ";
		cin >> setting_choice;

		switch (setting_choice) {
		case 1:  pcMode(); break;
		case 2: timeBombMode(); break;
		case 3: changeBoardSize(); break;
		case 4: changeBombTimer(); break;
		case 5: break;
		default: cout << "Please enter choice 1 - 5 only." << endl; system("pause");
		}
	} while (setting_choice != 5);
}

void Instructions()                //Shows the tutorial of this project. From input, marks, to mode selection.
{
	system("cls");
	int Marks = 100;
	cout << "Game  Instruction: \n\n\n";


	cout << " In Block Puzzle Game, Player scores by putting \nblocks of different shapes onto a square game board,\nand by producing complete horizontal or vertical \nlines of blocks and clear those lines.The Player can \nchange the game board size and select the Timer \nBomb Mode in the setting.\n\n";

	cout << " In the setting menu, you can input the starting \nbomb timer value ,but acceptable starting bomb timer \nvalue is from 6 to 9.Also,you can input the \nvalue to updat the square boradsize which between 7 × 7 \nto 10 × 10 only.\n\n";


	cout << "Player scores:";
	cout << endl;
	cout << setw(10) << "Number of complete lines formed in one move" << setw(13) << right << "Marks" << endl;
	for (int i = 1; i <= 6; i++) {
		cout << setw(15) << right << i << setw(40) << right << Marks;
		cout << endl;
		Marks = Marks + (i + 1) * 100;

	}
	cout << "Blocks types: " << endl;
	cout << "type 0:X     type 1:X X    type 2:X X X   type 3:X X X X type 4:X X X X X\n\n\n\n\n";
	cout << "type 5:X     type 6:X      type 7:X       type 8:X                \n";
	cout << "       X            X             X              X                \n";
	cout << "                    X             X              X                \n";
	cout << "                                  X              X                \n";
	cout << "                                                 X                \n\n\n";
	cout << "type 9:X     type10:  X    type11:X X     type12:X X               \n";
	cout << "       X X          X X           X                X               \n\n\n\n";
	cout << "type13:X     type14:    X  type15:X X X   type16:X X X              \n";
	cout << "       X                X         X                  X              \n";
	cout << "       X X X        X X X         X                  X              \n\n\n";
	cout << "type17:X X   type18:X X X                                      \n";
	cout << "       X X          X X X                                      \n";
	cout << "                    X X X                                      \n";
	system("pause");

}

void Credits()                                                     // Credits Mode. Shows all person involed in this project
{
	system("cls");
	cout << "Design and Development: Tsz Shun (Jason) CHU**\n";

	system("pause");
}


int Exit() {                         // Exit the system if user type 'y', which means yes. the whole system closes.
	system("cls");
	char exit;
	do {
		cout << "Confirm to end game? (y/n)" << endl;
		cin >> exit;
		cout << "\n";
		if ((exit == 'y') || (exit == 'Y'))
			return 1;
	} while ((exit != 'n') && (exit != 'N'));
	return 0;
}
