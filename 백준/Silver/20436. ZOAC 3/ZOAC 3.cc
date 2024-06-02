#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct MyPoint
{
    int x, y;
};

int main() {
    map<char, MyPoint> left;
    map<char, MyPoint> right;
    left['q'] = { 0,0 };
    left['w'] = { 0,1 };
    left['e'] = { 0,2 };
    left['r'] = { 0,3 };
    left['t'] = { 0,4 };
    left['a'] = { 1,0 };
    left['s'] = { 1,1 };
    left['d'] = { 1,2 };
    left['f'] = { 1,3 };
    left['g'] = { 1,4 };
    left['z'] = { 2,0 };
    left['x'] = { 2,1 };
    left['c'] = { 2,2 };
    left['v'] = { 2,3 };

    right['y'] = { 0,1 };
    right['u'] = { 0,2 };
    right['i'] = { 0,3 };
    right['o'] = { 0,4 };
    right['p'] = { 0,5 };
    right['h'] = { 1,1 };
    right['j'] = { 1,2 };
    right['k'] = { 1,3 };
    right['l'] = { 1,4 };
    right['b'] = { 2,0 };
    right['n'] = { 2,1 };
    right['m'] = { 2,2 };

    char l, r;
    cin >> l >> r;
    MyPoint currentLeft = left[l];
    MyPoint currentRight = right[r];

    string str;
    cin >> str;

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        count++;
        if (left.find(str[i]) != left.end())
        {
            count += abs(currentLeft.x - left[str[i]].x) + abs(currentLeft.y - left[str[i]].y);
            currentLeft = left[str[i]];
        }
        else if (right.find(str[i]) != right.end())
        {
            count += abs(currentRight.x - right[str[i]].x) + abs(currentRight.y - right[str[i]].y);
            currentRight = right[str[i]];
        }
    }
    cout << count;
    return 0;
}