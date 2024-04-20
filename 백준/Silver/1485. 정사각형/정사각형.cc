#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};


int calcDistance(Point a, Point b)
{
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

void Sort(vector <Point>& v)
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - 1 - i; j++)
        {
            if (v[j].x > v[j + 1].x)
                swap(v[j], v[j + 1]);

            else if(v[j].x == v[j + 1].x)
                if (v[j].y > v[j + 1].y)
                    swap(v[j], v[j + 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        vector <Point> v(4);
        for (int i = 0; i < 4; i++) {
            cin >> v[i].x >> v[i].y;
        }
        Sort(v);
        //2 3
        //0 1
        int s1 = calcDistance(v[0], v[1]); //선분
        int s2 = calcDistance(v[0], v[2]);
        int s3 = calcDistance(v[1], v[3]);
        int s4 = calcDistance(v[2], v[3]);

        int dia1 = calcDistance(v[0], v[3]); //대각선
        int dia2 = calcDistance(v[1], v[2]); //대각선
        if (s1 == s2 && s2 == s3 && s3 == s4 && dia1 == dia2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}