#include <iostream>
#include <vector>
using namespace std;

int board[19][19], boardSize= 19;
int point_x, point_y;

const int ways = 4;
const int dir[4][2] = {{1, 0}, //아래
                       {0, 1}, //오른쪽
                       {1, 1}, //오른쪽 아래 대각선
                       {-1, 1}}; //왼쪽 아래 대각선

int isWinner();
bool checkOmok(int x, int y, int stone);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int stone;
            cin >> stone;
            board[i][j] = stone;
        }
    }
    if (isWinner() == 1)
        cout << "1";
    else if (isWinner() == 2)
        cout << "2";
    else
    {
        cout << "0";
        return 0;
    }
    cout << "\n";
    cout << point_x+1  << " " << point_y+1;
    return 0;
}
int isWinner() {
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == 1)
            {
                if (checkOmok(i, j, 1))
                {
                    point_x = i;
                    point_y = j;
                    return 1;
                }
                    
            }
            else if (board[i][j] == 2)
            {
                if (checkOmok(i, j, 2))
                {
                    point_x = i;
                    point_y = j;
                    return 2;
                }
            }
        }
    }
    return 0;
}


bool checkOmok(int x, int y, int stone)
{
    for (int w = 0; w < ways; w++) {
        int cnt = 1; //이미 하나는 놓아져 있는 상태에서 탐색
        bool flag = false;
        int nx = x + dir[w][0], ny = y + dir[w][1];
        if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardSize) continue;
        while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == stone)
        {
            cnt++;
            if (cnt == 5 && board[nx + dir[w][0]][ny + dir[w][1]] != stone && board[x - dir[w][0]][y - dir[w][1]] != stone)
            {
                return true;
            }
            nx += dir[w][0];
            ny += dir[w][1];
        }
    }
    return false;
}