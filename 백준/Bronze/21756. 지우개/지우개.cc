#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque <int> d;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        d.push_back(i);
    }
    while (d.size() != 1)
    {
        int currentSize = d.size();
        for (int i = 1; i <= currentSize; i++)
        {
            if (i % 2 != 0)
            {
                d.pop_front();
            }
            else
            {
                d.push_back(d.front());
                d.pop_front();
            }
        }
    }
    cout << d.front();
    return 0;
}