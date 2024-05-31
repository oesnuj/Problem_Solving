#include <iostream>
#include <string>
using namespace std;

void printResult(int N);
char checkMine(int r, int c, int N);

int dx[8] = { 0,-1,0,1,-1,-1,1,1 };
int dy[8] = { 1,0,-1,0,1,-1,1,-1 };

char mines[10][10];   //지뢰 위치가 표시되어 있는 보드판
char opend[10][10];   //사용자가 열어놓은 위치를 저장하는 보드판
bool hitMine = false;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mines[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> opend[i][j];
            if (opend[i][j] == 'x') //사용자가 연 보드판이라면
                opend[i][j] = checkMine(i, j, n); //해당 위치 8방향의 지뢰갯수 표시
        }
    }
    if (hitMine)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mines[i][j] == '*') //사용자가 연 보드판이라면
                    opend[i][j] = '*'; //해당 위치 8방향의 지뢰갯수 표시
            }
        }
    }

    printResult(n);
   
    return 0;
}


void printResult(int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << opend[i][j]; //결과 보드판 출력
        }
        cout << '\n';
    }
}

char checkMine(int r, int c, int N) //해당위치로부터 8방향(상, 하, 좌, 우, 대각선)의 지뢰갯수 반환
{
    if (mines[r][c] == '*')//지뢰를 밟았다면
    {
        hitMine = true;
        return '*';
    }
        

    int count = 0;
    for (int i = 0; i < 8; i++) {
        int ny = r + dy[i], nx = c + dx[i];
        if ( ny < 0 || nx < 0 ||ny >= N || nx >= N)continue;
        if (mines[ny][nx] == '*')
            count++;
    }
    string cnt = to_string(count);
    return cnt[0];
}