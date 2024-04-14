#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;

};
bool compareInfo(Point& a, Point& b);
int countStoneToCapture(int x, int y, int boardSize);
int findPoint(int& computer_x, int& computer_y, int boardSize);
bool isValidMove(int x, int y, int boardSize);

vector<Point> flipCoords;
char board[500][500];

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
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n;
    cin >> n;
    const int boardSize = n;
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            cin >> board[i][j];
        }
    }

    int x, y;
    int maxFlips = findPoint(x, y, boardSize);
    if (maxFlips == 0)
    {
        cout << "PASS";
        return 0;
    }
    cout << y << " " << x << '\n';  //이 x가 행, y가 열이므로 문제의 x좌표는 열, y 좌표는 행이된다.
    //반대로 출력
    cout << maxFlips;

    return 0;
}

bool compareInfo(Point& a, Point& b)
{
    if (a.x == b.x) // x가 열을 나타내므로, 열이 같을 때 행을 비교합니다.
        return a.y < b.y;
    return a.x < b.x;
}

int countStoneToCapture(int x, int y, int boardSize) {  //잡을 수 있는 상대 말의 개수
    bool flipPossible = false;
    int totalFlips = 0;

    for (int i = 0; i < 8; ++i) {
        int dx = WAY[i][0];
        int dy = WAY[i][1];

        int nx = x + dx;
        int ny = y + dy;

        // 현재 방향으로 탐색을 시작하기 전에 먼저 다른 색의 돌을 만나는지 확인
        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == 'W') {
            bool currentDirectionFlipPossible = false;
            int currentDirectionFlips = 0;
            bool sameColorFound = false;
            // 다른 색의 돌을 만나면 현재 방향으로 계속해서 탐색
            while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                // 같은 색의 돌을 만나면 탐색을 중단하고 뒤집는 게 가능함을 표시
                if (board[nx][ny] == 'B') {
                    sameColorFound = true;
                    break;
                }
                // 빈 공간을 만나면 탐색을 중단하고 뒤집는 게 불가능함을 표시
                else if (board[nx][ny] == '.') {
                    break;
                }
                // 다른 색의 돌을 계속해서 만나면 탐색을 계속 진행
                nx += dx;
                ny += dy;
                currentDirectionFlips++;
            }

            // 같은 색의 돌이 있고, 뒤집는 게 가능하다면 해당 플립 수를 누적
            if (sameColorFound && currentDirectionFlips > 0) {
                totalFlips += currentDirectionFlips;
                flipPossible = true;
            }
        }
    }

    // 모든 방향에서 뒤집는 게 가능하다면 총 뒤집을 수 있는 돌의 수 반환
    if (flipPossible) {
        return totalFlips;
    }
    else {
        return 0; // 뒤집을 수 있는 돌이 없는 경우 0 반환
    }
}


int findPoint(int& computer_x, int& computer_y, int boardSize) {
    int maxFlips = 0;
    vector<Point> maxFlipsCoords;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (isValidMove(i, j, boardSize)) {
                int flips = countStoneToCapture(i, j, boardSize);
                if (flips > maxFlips) {
                    maxFlips = flips;
                    maxFlipsCoords.clear();
                    maxFlipsCoords.push_back({ i, j });
                }
                else if (flips == maxFlips) {
                    maxFlipsCoords.push_back({ i, j });
                }
            }
        }
    }

    if (!maxFlipsCoords.empty()) {
        sort(maxFlipsCoords.begin(), maxFlipsCoords.end(), compareInfo);
        computer_x = maxFlipsCoords[0].x;
        computer_y = maxFlipsCoords[0].y;
        return maxFlips;
    }
    else {
        // 놓을 수 있는 위치가 없을 때 0 return
        return 0;
    }
}

bool isValidMove(int x, int y, int boardSize)
{
    // 이미 돌이 놓여있는 경우 이동할 수 없습니다.
    if (board[x][y] != '.') return false;
    // 놓을 수 있는 위치인지 확인합니다.
    return countStoneToCapture(x, y, boardSize) > 0;
}