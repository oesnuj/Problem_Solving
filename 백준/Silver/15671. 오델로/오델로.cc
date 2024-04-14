//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void makeBoard();
void printBoard(char(*arr)[6]);
void flipStones(int x, int y, char color);
int countScore(char player);
void determineWinner();

struct Point
{
    int x;
    int y;

};
vector<Point> flipCoords;

const int boardSize = 6;
char board[boardSize][boardSize];



const int WAYS = 8;
const int WAY[8][2] = { { -1, 0 },
                        { 1, 0 },
                        { 0, -1 },
                        { 0, 1 },
                        { -1, 1 },
                        { -1, -1 },
                        { 1, -1 },
                        { 1, 1 } };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    makeBoard();
    int n;
    cin >> n;
    bool turn = true;

    vector <Point> input(n);
    for (auto k : input){
        cin >> k.x >> k.y;
        k.x -= 1;
        k.y -= 1;
        if (turn == true) //흑의 차례
        {
            board[k.x][k.y] = 'B';
            flipStones(k.x, k.y, 'B');
            turn = false;
        }
        else //백의 차례
        {
            board[k.x][k.y] = 'W';
            flipStones(k.x, k.y, 'W');
            turn = true;
        }

    }
    // 게임 루프
    printBoard(board);
    determineWinner();
    return 0;
}

void makeBoard()
{
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = '.';
        }
    }
    board[2][2] = 'W';
    board[2][3] = 'B';
    board[3][2] = 'B';
    board[3][3] = 'W';
    return;
}

void printBoard(char(*arr)[6])  //보드판 출력함수
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

void flipStones(int x, int y, char color) {
    board[x][y] = color; // 선택한 위치에 돌을 놓습니다.
    for (int i = 0; i < WAYS; ++i) {
        int dx = WAY[i][0];
        int dy = WAY[i][1];

        vector<Point> tempFlipCoords; // 임시로 뒤집을 돌의 좌표를 저장합니다.

        int nx = x + dx;
        int ny = y + dy;

        while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
            if (board[nx][ny] == '.') {
                break; // 빈 칸을 만나면 중단합니다.
            }
            if (board[nx][ny] == color) {
                for (auto& p : tempFlipCoords) { // 뒤집을 돌이 확정되었으므로 뒤집습니다.
                    board[p.x][p.y] = color;
                }
                break; // 같은 색의 돌을 만나면 루프를 종료합니다.
            }
            // 다른 색의 돌을 만나면 뒤집을 목록에 추가합니다.
            tempFlipCoords.push_back({ nx, ny });

            nx += dx;
            ny += dy;
        }
    }
}

int countScore(char color) {
    int score = 0;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == color) {
                score++;
            }
        }
    }
    return score;
}

void determineWinner() {
    int blackScore = countScore('B');
    int whiteScore = countScore('W');

    if (blackScore > whiteScore) {
        cout << "Black" << endl;
    }
    else if (blackScore < whiteScore) {
        cout << "White" << endl;
    }
}