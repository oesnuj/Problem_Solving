#include <stdio.h>


int main()
{
    int arr[100];
    int N;
    int count = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d",&arr[i]);
    int K;
    scanf("%d", &K);
    for (int j = 0; j < N; j++)
        if (arr[j] == K)
            count++;
    printf("%d", count);
    return 0;
}