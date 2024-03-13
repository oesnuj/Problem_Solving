#include <iostream>
using namespace std;

int main() {
    int n, m, arr[300][300];
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long int sum = 0;
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        for (int a = i - 1; a < x; a++){
            for (int b = j - 1; b < y; b++){
                sum += arr[a][b];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}