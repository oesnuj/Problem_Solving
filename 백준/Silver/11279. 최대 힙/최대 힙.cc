#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    priority_queue <int> q; //우선순위 큐 활용
    int n;    cin >> n;
    while (n--)
    {
        long long int x;
        cin >> x;
        if (x == 0)
        {
            if (!q.empty())
            {
                cout << q.top() << '\n';
                q.pop();
            }
            else
                cout << 0 << '\n';
        }   
        else
            q.push(x);
    }
        
    return 0;
}