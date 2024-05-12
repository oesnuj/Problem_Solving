#include <iostream>
#include <queue>
using namespace std;
struct content
{
    int index;
    int priority;
};

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue <int> pq;
        queue <content> q;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
            q.push({ i, x });
        }
        int count = 0;
        while (1)
        {
            if (pq.top() == q.front().priority)
            {
                pq.pop();
                count++;
                if (m == q.front().index)
                {
                    cout << count << '\n';
                    break;
                }
            }
            else
                q.push(q.front());
            q.pop();         
        }
    }
    return 0;
}