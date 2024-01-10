#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int A[10000];
    int B[10000];

    // 행렬 A의 원소 입력
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> A[i * M + j]; // 올바른 인덱스 계산
        }
    }

    // 행렬 B의 원소 입력
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> B[i * M + j]; // 올바른 인덱스 계산
        }
    }

    // 합 행렬 계산
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << A[i * M + j] + B[i * M + j] << " ";
        }
        cout << endl;
    }
    return 0;
}