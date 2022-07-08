#include "TicTacToe.h"

void TicTacToe::play()
{
	cout << "Welcome to Ghost's version of Tic Tac Toe, Enjoy :) \n\n";

	cout << "What is your name player one? ";
	getline(cin, player1);

	cout << "\nWhat is your name player two? ";
	getline(cin, player2);
	
	
	while (flag)
	{
		char p[] = { '0','1','2','3','4','5','6','7','8','9' };


		do {
			i++;

			if (i > 9 || i == -1) //checks if there is a draw
				break;

			print(p, player1, player2, p1_score, p2_score); //prints the layout before the player playing his turn 

			whose_turn(i, p, input, player1, player2);//decides whose turn it is and if there is any input errors

			print(p, player1, player2, p1_score, p2_score);//prints the layout after the player playing his turn 

		} while (!check_Win(p));




		if (i > 9 || i == -1)

		{
			cout << "Draw!\n";
			cout << "If you want to play again press (1) ,If you want to close the game press(0)\n";
			cin >> flag;
			int random[2] = { 0, -11 };
			int random_index = rand() % 2 + 0; //if there is a draw its random who is starting next round

			i = random[random_index];
		}
		else if (abs(i) % 2 == 0)
		{
			cout << player2 << " won!\n";//make a function for it
			cout << "If you want to play again press (1) ,If you want to close the game press(0)\n";
			cin >> flag;
			i = -11; //if you win you play first next round
			p2_score++;
		}
		else
		{
			cout << player1 << " won!\n";
			cout << "If you want to play again press (1) ,If you want to close the game press(0)\n";
			cin >> flag;
			i = 0; //if you win you play first next round
			p1_score++;
		}


	}


	if (p1_score == p2_score)
		cout << "The final score is " << p1_score << " - " << p2_score << "\nThis match ended with a Draw.\n";
	else if (p1_score > p2_score)
		cout << "The final score is " << p1_score << " - " << p2_score << endl << player1 << " is victorious EZ.\n";
	else
		cout << "The final score is " << p1_score << " - " << p2_score << endl << player2 << " is victorious EZ.\n";

	cout << "Thank you for playing <3.\n";


}


void TicTacToe::print(char p[], string p1, string p2, int a, int b)
{
	system("CLS");
	cout << p1 << "(X) - " << p2 << "(O)\n";
	cout << "Score: " << p1 << " = " << a << " - " << p2 << " = " << b;
	cout << "\n             |     |     \n"
		"          " << p[1] << "  |  " << p[2] << "  |  " << p[3] << "  \n"
		"        _____|_____|_____\n"
		"             |     |     \n"
		"          " << p[4] << "  |  " << p[5] << "  |  " << p[6] << "  \n"
		"        _____|_____|_____\n"
		"             |     |     \n"
		"          " << p[7] << "  |  " << p[8] << "  |  " << p[9] << "  \n"
		"             |     |     \n";
}

bool TicTacToe::check_Win(char p[])
{
	for (int j = 1; j < 8; j++)
	{
		if (j == 1 || j == 4 || j ==7)
		{
			if (check_Win(p, j, 1))

				return true;
		}
		
		if (j == 1 || j == 2 || j == 3)
		{
			if (check_Win(p, j, 3))

				return true;
		}
		 
		if (j == 1 || j == 3)
		{
			int skip = 4;
			(j == 3) ? skip = 2 : skip = 4;

			if (check_Win(p, j, skip))
			{

				return true;
		    }
		}
    }
	
	return false;
}

bool TicTacToe::check_Win(char p[], int j, int skip)
{
	if (p[j] == p[j + skip] && p[j + skip] == p[j + (2 * skip)])
		return true;
	else
		return false;
}

int TicTacToe::check_input_error(int& input, char p[])
{
	bool invalid_input = true;

	while (invalid_input)
	{
		
		if (input >= 10 || input <= 0)
		{
			cout << "Invalid input please enter a number between 1 and 9: ";
			cin >> input;
			check_input_error(input, p);
		}
		
		if (p[input] == 'X' || p[input] == 'O')
		{
			cout << "Slot already used please choose another number: ";
			cin >> input;
			check_input_error(input, p);
		}
		else
		{
			invalid_input = false;
		}
	}
	return input;
}

void TicTacToe::whose_turn(int i, char p[], int& input, string player1, string player2)
{
	if (abs(i) % 2 == 0)
	{
		cout << player2 << " enter your number: ";
		cin >> input;

		//checks for input errors
		check_input_error(input, p);

		p[input] = 'O';

	}
	else
	{
		cout << player1 << " enter your number: ";
		cin >> input;

		//checks for input errors
		check_input_error(input, p);

		p[input] = 'X';
	}
}
