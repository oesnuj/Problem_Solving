#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    vector <int> v(n+1);
    v[1] = 0;
    for (int i = 2; i <= n; i++){ //벡터 0만 안들어가게 초기화
        v[i] = i;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i] == 0)
            continue;
        for (int j = i * i; j <= n; j += i) //아리스토텔레스의 체 방식 사용
        {
            v[j] = 0;
        }
    }       
    for (int i = m; i <= n; i++)
    {
        if (v[i] != 0) //0으로 초기화 되지 않은 경우 소수임
            cout << i << '\n';
    }
    return 0;
}