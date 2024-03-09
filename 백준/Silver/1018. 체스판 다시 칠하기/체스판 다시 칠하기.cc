#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char arr[51][51];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }

    }
    bool myBool = true;
    int min_count = 64;
    char CheckArr1[8] = { 'B', 'W', 'B' ,'W' ,'B' ,'W', 'B', 'W'};
    char CheckArr2[8] = { 'W', 'B', 'W' ,'B' ,'W' ,'B', 'W', 'B' };

    for (int x = 0; x < n - 7;x++)
    {
        for (int y = 0; y < m - 7; y++)
        {
            int count1 = 0, count2 = 0;
            for (int i = x; i < 8 + x; i++)
            {
                int index = 0;
                myBool = !myBool;
                for (int j = y; j < 8 + y; j++)
                {
                    if (myBool) //번갈아 가면서 계산(짝수행, 홀수행)
                    {
                        if (arr[i][j] != CheckArr1[index]) //B로 시작하는 행일 경우 계산
                            count1++;
                        if (arr[i][j] != CheckArr2[index]) //W로 시작하는 행일 경우 계산
                            count2++;
                    }
                    else 
                    {
                        if (arr[i][j] != CheckArr2[index])
                            count1++;
                        if (arr[i][j] != CheckArr1[index])
                            count2++;
                    }
                    index++;
                }
            }
            min_count = min(min_count, min(count1, count2)); 
            //B로 시작, W로 시작중의 최솟값과 지금까지의 최솟값을 비교
        }
    }
    cout << min_count;
    return 0;
}