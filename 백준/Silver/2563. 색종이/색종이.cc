#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10; //정사각형 색종이 한변의 길이 상수로 선언
    int x, y, n, count = 0;
    int paper[100][100] = {0};
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> x >> y;
        for (int i = x - 1; i < x + SIZE - 1; i++){
            for (int j = y - 1; j < y + SIZE - 1; j++){
                if (paper[i][j] == 0)
                {
                    paper[i][j] = 1;
                    count++;
                }    
            }
        }
    }
    cout << count;
    return 0;
}