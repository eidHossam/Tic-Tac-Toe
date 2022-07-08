#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class TicTacToe
{
private:
	string player1, player2;
	bool flag = true;
	int input = 0;
	int i = 0;
	int p1_score = 0, p2_score = 0;

	void print(char p[], string p1, string p2, int a, int b);
	bool check_Win(char p[]);
	bool check_Win(char p[], int j, int skip);
	int check_input_error(int& input, char p[]);
	void whose_turn(int i, char p[], int& input, string player1, string player2);

public :
	void play();
};

