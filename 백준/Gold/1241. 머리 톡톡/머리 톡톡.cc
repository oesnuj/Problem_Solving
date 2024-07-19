#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> circle(n); //1부터 n까지 학생의 번호를 저장
    vector <int> num(1000001);//각 번호별로의 학생 수를 저장
    for (int i = 0; i < n; i++) {
        int x;
        cin >> circle[i];
        num[circle[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int result = 0;
        int k = circle[i];
        for (int j = 1; j * j <= k; j++) {
            if (k % j == 0) //나누어 떨어지는 약수 인 경우라면
            {
                if (j * j != k) result += (num[j] + num[k / j]);
                else result += num[j];
            }
        }
        cout << result - 1 << "\n";
    }
    return 0;
}