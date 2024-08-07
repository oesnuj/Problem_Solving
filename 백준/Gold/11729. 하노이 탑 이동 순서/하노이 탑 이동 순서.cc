#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void RecurMoveDisks(int n, int from, int temp, int to) {
    if (n == 0) return;
    //n-1개의 원판으로 temp로 옮긴다.
    RecurMoveDisks(n - 1, from, to, temp);

    //남은 1개의 원판으로 to로 옮긴다. <- 이때 옮기는 과정 출력
    cout << from << " " << to << "\n";

    //temp에 있던 n-1개의 원판을 n-1개로 옮긴다.
    RecurMoveDisks(n - 1, temp, from, to);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;

    //2의 n제곱 -1 출력하기
    string a = to_string(pow(2, n));
    int x = a.find('.');
    a = a.substr(0, x);
    a[a.length() - 1] -= 1;
    cout << a << "\n";

    //조건에 맞는 경우에만 재귀를 돌린다.
    if (n <= 20)  RecurMoveDisks(n, 1, 2, 3);
    return 0;
}