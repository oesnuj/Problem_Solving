#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n;
    cin >> n;

    int sum = 0;
    int i = 1;
    while (true)
    {
        sum += i;  //i가 해당 라인을 의미한다.
        if (sum >= n) //이시점에 해당 라인에 도착
            break;
        i++;
    }
    if (i % 2 == 0) //짝수라면
        cout << n - (sum - i) << "/" << 1 - n + sum;
    else //홀수라면
        cout << 1 - n + sum << "/" << n - (sum - i);
    return 0;        

}