#include <iostream>

using namespace std;

int calc(int k, int n) {
    //0층이라면 n이 거주자수
    if (k == 0) 
    { 
        return n;
    }

    else //0층이 아니라면, 해당 아래층의 합
    {
        int sum = 0;
        for (int i = n; i > 0; i--) {
            sum += calc(k - 1, i);
        }
        return sum;
    }
}


int main() 
{
    int T, k, n;
    cin >> T;
    while (T--) {
        cin >> k >> n;
        cout << calc(k, n) << "\n";
    }

    return 0;
}