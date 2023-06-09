#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<fstream>
#include<iomanip>
using namespace std;
int playerOne[5][5] = {  // initilize array of player one
	0
};
int playerTwo[5][5] = {  // initialize array of player two
	0
};
string playerOneName, playerTwoName;
bool playerCheck[24] = { true };
int playerOneScore = 0, playerTwoScore = 0;
void drawBoard() {
	cout << "\t\tPlayer 1 Board :" << endl << endl;
	for (int a = 0; a != 5; a++) {                   //draw board for player one
		for (int b = 0; b != 5; b++) {
			cout << setw(5) << playerOne[a][b] << " |  ";
		}
		cout << endl;
	}
	cout << "\n\n\t\tPlayer 2 Board :" << endl << endl;
	for (int a = 0; a != 5; a++) {
		for (int c = 0; c != 5; c++) {                 //draw board for player two
			cout << setw(5) << playerTwo[a][c] << " |  ";
		}
		cout << endl;
	}
}
bool checkDuplicatePlayers(int number, int turn) {

	bool check = false; // using bool for this purpose that only unique number will generate
	if (turn == 1)
	{
		for (int a = 0; a != 5; a++)
		{
			for (int b = 0; b != 5; b++)
			{
				if (playerOne[a][b] == number)
				{
					check = true;    // check is for the bool
				}
			}
		}
	}
	else
	{
		for (int a = 0; a != 5; a++)
		{
			for (int b = 0; b != 5; b++)
			{
				if (playerTwo[a][b] == number)
				{
					check = true;
				}
			}
		}
	}
	return check;
}
void initializingArrays() {
	for (int a = 0; a != 24; a++) {
		playerCheck[a] = true;
	}
		for (int a = 0; a != 5; a++) {
		for (int b = 0; b != 5; b++) {
			bool flagOne = true;
			bool flagTwo = true;
			int number;                       //checking that no same number will rupete agin
			while (flagOne)
			{
				number = rand() % 25 + 1;
				flagOne = checkDuplicatePlayers(number, 1);
			}
			playerOne[a][b] = number;
			while (flagTwo)
			{
				number = rand() % 25 + 1;
				flagTwo = checkDuplicatePlayers(number, 0);
			}
			playerTwo[a][b] = number;
		}
		cout << endl;
	}
}
void replacingValues(int value) {
	for (int a = 0; a != 5; a++) {
		for (int b = 0; b != 5; b++) {
			if (playerOne[a][b] == value) {
				playerOne[a][b] = 0;               //the user who select the number will be replaced by zero
			}
			if (playerTwo[a][b] == value) {
				playerTwo[a][b] = 0;
			}
		}
	}
	
}
void checkBingo(int turn) {     //using this logic for the combinations of bingo for the player one
	if (playerCheck[0])  // columns canceling for first player
	{
		if ((playerOne[0][0] == playerOne[1][0]) && (playerOne[1][0] == playerOne[2][0]) && (playerOne[2][0] == playerOne[3][0]) && (playerOne[3][0] == playerOne[4][0]) && (playerOne[1][0] == 0)) {
			playerOneScore += 1;
			playerCheck[0] = false;
		}
	}
	if (playerCheck[1])
	{
		if ((playerOne[0][1] == playerOne[1][1]) && (playerOne[1][1] == playerOne[2][1]) && (playerOne[2][1] == playerOne[3][1]) && (playerOne[3][1] == playerOne[4][1]) && (playerOne[1][1] == 0)) {
			playerOneScore += 1;
			playerCheck[1] = false;
		}
	}
	if (playerCheck[2])
	{
		if ((playerOne[0][2] == playerOne[1][2]) && (playerOne[1][2] == playerOne[2][2]) && (playerOne[2][2] == playerOne[3][2]) && (playerOne[3][2] == playerOne[4][2]) && (playerOne[1][2] == 0)) {
			playerOneScore += 1;
			playerCheck[2] = false;
		}
	}
	if (playerCheck[3])
	{
		if ((playerOne[0][3] == playerOne[1][3]) && (playerOne[1][3] == playerOne[2][3]) && (playerOne[2][3] == playerOne[3][3]) && (playerOne[3][3] == playerOne[4][3]) && (playerOne[1][3] == 0)) {
			playerOneScore += 1;
			playerCheck[3] = false;
		}
	}
	if (playerCheck[4])
	{
		if ((playerOne[0][3] == playerOne[1][3]) && (playerOne[1][3] == playerOne[2][3]) && (playerOne[2][3] == playerOne[3][3]) && (playerOne[3][3] == playerOne[4][3]) && (playerOne[1][3] == 0)) {
			playerOneScore += 1;
			playerCheck[4] = false;
		}
	}
	if (playerCheck[5])
	{
		if ((playerOne[0][4] == playerOne[1][4]) && (playerOne[1][4] == playerOne[2][4]) && (playerOne[2][4] == playerOne[3][4]) && (playerOne[3][4] == playerOne[4][4]) && (playerOne[1][4] == 0)) {
			playerOneScore += 1;
			playerCheck[5] = false;
		}
	}
	//			Rows Canceling for first player__________________________________________________________________________________________________
	if (playerCheck[6])
	{
		if ((playerOne[0][0] == playerOne[0][1]) && (playerOne[0][1] == playerOne[0][2]) && (playerOne[0][2] == playerOne[0][3]) && (playerOne[0][3] == playerOne[0][4]) && (playerOne[0][1] == 0)) {
				playerOneScore += 1;
			playerCheck[6] = false;
		}
	}
	if (playerCheck[7])
	{
		if ((playerOne[1][0] == playerOne[1][1]) && (playerOne[1][1] == playerOne[1][2]) && (playerOne[1][2] == playerOne[1][3]) && (playerOne[1][3] == playerOne[1][4]) && (playerOne[1][1] == 0)) {
			playerOneScore += 1;
			playerCheck[7] = false;
		}
	}
	if (playerCheck[8])
	{
		if ((playerOne[2][0] == playerOne[2][1]) && (playerOne[2][1] == playerOne[2][2]) && (playerOne[2][2] == playerOne[2][3]) && (playerOne[2][3] == playerOne[2][4]) && (playerOne[2][1] == 0)) {
			playerOneScore += 1;
			playerCheck[8] = false;
		}
	}
	if (playerCheck[9])
	{
		if ((playerOne[4][0] == playerOne[4][1]) && (playerOne[4][1] == playerOne[4][2]) && (playerOne[4][2] == playerOne[4][3]) && (playerOne[4][3] == playerOne[4][4]) && (playerOne[4][1] == 0)) {
			playerOneScore += 1;
			playerCheck[9] = false;
		}
	} 
	//  Diagonal cancelling for first player
	if (playerCheck[10])
	{
		// Left to right
		if ((playerOne[0][0] == playerOne[1][1]) && (playerOne[1][1] == playerOne[2][2]) && (playerOne[2][2] == playerOne[3][3]) && (playerOne[3][3] == playerOne[4][4]) && (playerOne[0][0] == 0)) {
			playerOneScore += 1;
			playerCheck[10] = false;
		}
	}
	if (playerCheck[11])
	{
		// Right to left
		if ((playerOne[0][4] == playerOne[1][3]) && (playerOne[1][3] == playerOne[2][2]) && (playerOne[2][2] == playerOne[3][1]) && (playerOne[3][1] == playerOne[4][0]) && (playerOne[4][0] == 0)) {
			playerOneScore += 1;
			playerCheck[11] = false;
		}
	}
	//using this logic for the combinations of bingo for the player 2 
	if (playerCheck[12])
	{
		// Columns canceling for player two 
		if ((playerTwo[0][0] == playerTwo[1][0]) && (playerTwo[1][0] == playerTwo[2][0]) && (playerTwo[2][0] == playerTwo[3][0]) && (playerTwo[3][0] == playerTwo[4][0]) && (playerTwo[1][0] == 0)) {
			playerTwoScore += 1;
			playerCheck[12] = false;
		}
	}
	if (playerCheck[13])
	{
		if ((playerTwo[0][1] == playerTwo[1][1]) && (playerTwo[1][1] == playerTwo[2][1]) && (playerTwo[2][1] == playerTwo[3][1]) && (playerTwo[3][1] == playerTwo[4][1]) && (playerTwo[1][1] == 0)) {
			playerTwoScore += 1;
			playerCheck[13] = false;
		}
	}
	if (playerCheck[14])
	{
		if ((playerTwo[0][2] == playerTwo[1][2]) && (playerTwo[1][2] == playerTwo[2][2]) && (playerTwo[2][2] == playerTwo[3][2]) && (playerTwo[3][2] == playerTwo[4][2]) && (playerTwo[1][2] == 0)) {
			playerTwoScore += 1;
			playerCheck[14] = false;
		}
	}
	if (playerCheck[15])
	{
		if ((playerTwo[0][3] == playerTwo[1][3]) && (playerTwo[1][3] == playerTwo[2][3]) && (playerTwo[2][3] == playerTwo[3][3]) && (playerTwo[3][3] == playerTwo[4][3]) && (playerTwo[1][3] == 0)) {
			playerTwoScore += 1;
			playerCheck[15] = false;
		}
	}
	if(playerCheck[16])
	if ((playerTwo[0][4] == playerTwo[1][4]) && (playerTwo[1][4] == playerTwo[2][4]) && (playerTwo[2][4] == playerTwo[3][4]) && (playerTwo[3][4] == playerTwo[4][4]) && (playerTwo[1][4] == 0)) {
		playerTwoScore += 1;
		playerCheck[16] = false;
	}
	//			Rows canceling for player two_________________________________________________________________________________________________
	if (playerCheck[17])
	{
		if ((playerTwo[0][0] == playerTwo[0][1]) && (playerTwo[0][1] == playerTwo[0][2]) && (playerTwo[0][2] == playerTwo[0][3]) && (playerTwo[0][3] == playerTwo[0][4]) && (playerTwo[0][1] == 0)) {
			playerTwoScore += 1;
			playerCheck[17] = false;
		}
	}
	if (playerCheck[18])
	{
		if ((playerTwo[1][0] == playerTwo[1][1]) && (playerTwo[1][1] == playerTwo[1][2]) && (playerTwo[1][2] == playerTwo[1][3]) && (playerTwo[1][3] == playerTwo[1][4]) && (playerTwo[1][1] == 0)) {
			playerTwoScore += 1;
			playerCheck[18] = false;
		}
	}
	if (playerCheck[19])
	{
		if ((playerTwo[2][0] == playerTwo[2][1]) && (playerTwo[2][1] == playerTwo[2][2]) && (playerTwo[2][2] == playerTwo[2][3]) && (playerTwo[2][3] == playerTwo[2][4]) && (playerTwo[2][1] == 0)) {
			playerTwoScore += 1;
			playerCheck[19] = false;
		}
	}
	if (playerCheck[20])
	{
		if ((playerTwo[3][0] == playerTwo[3][1]) && (playerTwo[3][1] == playerTwo[3][2]) && (playerTwo[3][2] == playerTwo[3][3]) && (playerTwo[3][3] == playerTwo[3][4]) && (playerTwo[3][1] == 0)) {
			playerTwoScore += 1;
			playerCheck[20] = false;
		}
	}
	if (playerCheck[21])
	{
		if ((playerTwo[4][0] == playerTwo[4][1]) && (playerTwo[4][1] == playerTwo[4][2]) && (playerTwo[4][2] == playerTwo[4][3]) && (playerTwo[4][3] == playerTwo[4][4]) && (playerTwo[4][1] == 0)) {
			playerTwoScore += 1;
			playerCheck[21]=false;
		}
	} // Diagonal Canceling for player two
	if (playerCheck[22])
	{ // from left to right
		if ((playerTwo[0][0] == playerTwo[1][1]) && (playerTwo[1][1] == playerTwo[2][2]) && (playerTwo[2][2] == playerTwo[3][3]) && (playerTwo[3][3] == playerTwo[4][4]) && (playerTwo[0][0] == 0)) {
			playerTwoScore += 1;
			playerCheck[22] = false;
		}
	}
	if (playerCheck[23])
	{ // from right to left
		if ((playerTwo[0][4] == playerTwo[1][3]) && (playerTwo[1][3] == playerTwo[2][2]) && (playerTwo[2][2] == playerTwo[3][1]) && (playerTwo[3][1] == playerTwo[4][0]) && (playerTwo[4][0] == 0)) {
			playerTwoScore += 1;
			playerCheck[23] = false;
		}
	}
}
void checkWinning(int turn) {
	if (playerOneScore >= 5) {
		system("CLS");
		ofstream myScore("Score.txt");
		int gameId = rand();
		myScore << "Game Id " << gameId<<endl;
		myScore << "Player 1 wins : "<<playerOneName << endl;
		myScore << "Player 1 score = 5" << endl;
		cout << "\t\t\tPlayer 1 wins " << endl;        //if the player score will be 5 declareing the player one as a winner
		system("pause");
		exit(1);
	}
	if (playerTwoScore >= 5) {
		system("CLS");
		ofstream myScore("Score.txt");
		int gameId = rand();
		myScore << "Game Id " << gameId << endl;
		myScore << "Player 2 wins : " <<playerTwoName<< endl;
		myScore << "Player 2 score = 5" << endl;
		cout << "\t\t\tPlayer 2 wins " << endl;         //if player two score 5 than the player 2 won
		system("pause");
		exit(1);
	}
}
void startGame()
{
	srand(time(0));
	cout << "Enter Player 1 name : ";
	cin >> playerOneName;
	cout << "Enter Player 2 name : ";
	cin >> playerTwoName;
	system("CLS");
	initializingArrays();
	while (1) {
		drawBoard();
		int playerOneInput, playerTwoInput;
		cout << endl << playerOneName<< " score : " << playerOneScore;
		cout << "\t\t\t\t\t\t"<<playerTwoName<<" score : " << playerTwoScore << endl << endl;
		cout << "Enter Your Input  " <<playerOneName<<endl;
		while (true) {
			cin >> playerOneInput;
			if ((playerOneInput > 25) || (playerOneInput < 1)) {  // user will enter only in range of 1 to 25 if else than he will ask again input
				cout << "Invalid Number please try again" << endl;
			}
			else {
				break;
			}
		}
		replacingValues(playerOneInput);
		checkBingo(1);                       //this is checking winning condition for player one
		checkWinning(1);
		system("CLS");
		drawBoard();
		cout << endl << playerOneName << " score : " << playerOneScore;
		cout << "\t\t\t\t\t\t" << playerTwoName << " score : " << playerTwoScore << endl << endl;
		cout << "Enter Your Input  "<<playerTwoName<<endl;
		while (true) {
			cin >> playerTwoInput;
			if ((playerTwoInput > 25) || (playerTwoInput < 1)) {
				cout << "Invalid Number please try again" << endl;    //the same logic for player two to enter input between 1 and 25
			}
			else {
				break;
			}
		}
		replacingValues(playerTwoInput);
		checkBingo(2);                      //this is checking winning condition for player 2
		checkWinning(2);
		system("CLS");
	}
}
void mainMenu()
{
	int menuChoice;
	while(1)
	{
		cout <<"\t============Bingo Game=============";
		cout << "\n\n\t\tWelcome To the Game\n\n ";
		cout << "\t\t1) Play Game \n\n";
		cout << "\t\t2) Game History \n\n";
		cout << "\t\t3) How to play Game \n\n";
		cout << "\t\t4) Exit \n\n";
		cout << "\t\t5) Clear Screen \n\n";
		cout << "\t==================================" << endl << endl;
		cout << "\tEnter Your Choice---> ";
		cin >> menuChoice;
		cout<<endl;
		if (menuChoice == 1)
			startGame();
		else if (menuChoice == 3)
		{
			char arrayText[500];
			char arrayText1[500];
			char arrayText2[500];
			ifstream instructionFile("Instructions.txt");
			instructionFile.getline(arrayText, 200);
			instructionFile.getline(arrayText1,200);
			instructionFile.getline(arrayText2,200);
			cout << "Instructions are as follows: " << endl << endl;
			cout << "\t" << arrayText << endl << endl;
			cout << "\t" << arrayText1 << endl << endl;
			cout << "\t" << arrayText2 << endl << endl;
			instructionFile.close();
		}
		else if (menuChoice == 2)
		{
			ifstream  myScore("Score.txt");
			string getScore;
			if (!myScore.eof()) {
				while (myScore.good()) {
					cout << getScore << " ";
					myScore >> getScore;
				}
				cout<<endl;
			}
			myScore.close();
			cout << "\n";
		}
		else if (menuChoice==5)
		{
			system("CLS");
		}
		else
		{
			exit(1);
		}
	}
}
int main() {
	mainMenu();             //menu driven programme
	system("pause");
}
