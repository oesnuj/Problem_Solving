#include <iostream>
#include <vector>
using namespace std;

int board[100][100] = {0}; //2차원 그리드 0으로 초기화

struct MyPoint
{
    int x;
    int y;
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 0; i < 4; i++)
    {
        MyPoint ll, ru;
        cin >> ll.x >> ll.y >> ru.x >> ru.y;
        for (int i = ll.x; i < ru.x; i++)
        {
            for (int j = ll.y; j < ru.y; j++)
            {
                if(!board[i][j]) //사각형 부분 1로 채우기
                    board[i][j] = 1;
            }
        }
    }
    //1인 부분 다 더하기
    int area = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (board[i][j])
                area += 1;
        }
    }
    cout << area;
    return 0;
}
