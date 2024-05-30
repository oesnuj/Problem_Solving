#include <iostream>
using namespace std;

void changeBingo(int target);
int checkBingo();
const int BINGO_SIZE = 5;
int board[BINGO_SIZE][BINGO_SIZE];

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			cin >> board[i][j];
		}
	}

	int sayCnt = 0;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		for (int j = 0; j < BINGO_SIZE; j++)
		{
			int num;
			cin >> num;
			sayCnt++;
			changeBingo(num);
			if (checkBingo() >= 3) {
				cout << sayCnt;
				return 0;
			}
		}
	}
	return 0;
}


void changeBingo(int target)
{
	for (int i = 0; i < BINGO_SIZE; i++){
		for (int j = 0; j < BINGO_SIZE; j++){
			if (board[i][j] == target){
				board[i][j] = 0;
				return;
			}
		}
	}
	return;
}

int checkBingo()
{
	int bingoCnt = 0;
	
	for (int i = 0; i < BINGO_SIZE; i++) 
	{
		int horizontal = 0, vertical = 0;
		for (int j = 0; j < BINGO_SIZE; j++){
			if (!board[i][j])
				horizontal++;
			if (!board[j][i])
				vertical++;
		}
		if (horizontal == BINGO_SIZE) bingoCnt++;
		if (vertical == BINGO_SIZE) bingoCnt++;
	}													

	int right_diagonal = 0, left_diagonal = 0;
	for (int i = 0; i < BINGO_SIZE; i++)
	{
		if (!board[i][i]) right_diagonal++;
		if (!board[i][BINGO_SIZE - i - 1]) left_diagonal++;
	}
	if (right_diagonal == BINGO_SIZE) bingoCnt++;
	if (left_diagonal == BINGO_SIZE) bingoCnt++;

	return bingoCnt;
}