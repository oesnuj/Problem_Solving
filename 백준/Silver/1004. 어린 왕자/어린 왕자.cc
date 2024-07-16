#include <iostream>
#include <cmath>

using namespace std;

float calcDistance(int& x1, int& y1, int& x2, int& y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int T, x1, y1, x2, y2, cx, cy, r, n;
    float distance = 0;
    cin >> T;
    while (T--) {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        while (n--) {
            cin >> cx >> cy >> r;
            bool start_in_circle = calcDistance(x1, y1, cx, cy) <= r;
            bool end_in_circle = calcDistance(x2, y2, cx, cy) <= r;
            if (start_in_circle != end_in_circle) sum++;
        }
        cout << sum << '\n';
    }
    return 0;
}
