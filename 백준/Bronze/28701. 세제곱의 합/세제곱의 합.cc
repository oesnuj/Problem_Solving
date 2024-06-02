#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    for (int i = 1; i <= n; i++)
    {
        a += i;
        b += (i * i * i);
    }
    cout << a << '\n' << a * a << '\n' << b;
    return 0;
}
