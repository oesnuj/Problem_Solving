#include <iostream>
using namespace std;

int main()
{
    int max_num = 0, max_index_r = 1, max_index_c = 1;
    int** matrix = new int *[9]; //포인터의 배열 선언
    for (int r = 0; r < 9; r++)
        matrix[r] = new int[9]; //각 행에 있는 열의 수만큼 배열 선언

   
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            cin >> matrix[r][c];
            if (matrix[r][c] > max_num)
            {
                max_num = matrix[r][c];
                max_index_r = r+1; //문제에서 행렬의 인덱스가 1부터 시작
                max_index_c = c+1;
            }
        }
    }
    cout << max_num << endl;
    cout << max_index_r << " " << max_index_c;
    return 0;
}