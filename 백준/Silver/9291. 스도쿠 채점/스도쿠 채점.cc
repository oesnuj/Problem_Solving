#include <iostream>
#include <cstring>
using namespace std;
int grid[9][9], tc;
bool isVisited[10];
void input()
{
    for (int col = 0; col < 9; ++col)
    {
        for (int row = 0; row < 9; ++row)
        {
            cin >> grid[col][row];
        }
    }
}
bool caseCheck()
{
    for (int col = 0; col < 9; ++col) // 각 세로줄마다 가로 확인
    {
        memset(isVisited, false, sizeof(isVisited));
        for (int row = 0; row < 9; ++row)
        {
            int num = grid[col][row];
            if (isVisited[num]) // 이미 방문했다면
            {
                return false;
            }
            isVisited[num] = true;
        }
    }

    for (int row = 0; row < 9; ++row) // 각 가로줄마다 세로 확인
    {
        memset(isVisited, false, sizeof(isVisited));
        for (int col = 0; col < 9; ++col)
        {
            int num = grid[col][row];
            if (isVisited[num]) // 이미 방문했다면
            {
                return false;
            }
            isVisited[num] = true;
        }
    }

    for (int col = 0; col < 9; col += 3) // 3칸씩 띄어넘어서 정사각형 확인
    {
        for (int row = 0; row < 9; row += 3)
        {
            memset(isVisited, false, sizeof(isVisited));
            for (int c = 0; c < 3; ++c)
            {
                for (int r = 0; r < 3; ++r)
                {
                    int num = grid[col + c][row + r];
                    if (isVisited[num]) // 이미 방문했다면
                    {
                        return false;
                    }
                    isVisited[num] = true;
                }
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        input();
        cout << "Case " << i << ": " << (caseCheck() ? "CORRECT" : "INCORRECT") << "\n"; // 확인 결과에 따라 다르게 출력
    }
    return 0;
}