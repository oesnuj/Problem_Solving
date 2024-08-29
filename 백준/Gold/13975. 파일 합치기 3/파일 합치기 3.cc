#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        priority_queue <long long int, vector<long long int>, greater<long long int>> pq;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x; 
            pq.push(x);
        }
        long long int result = 0;
        while (pq.size() > 1)
        {
            long long int a = pq.top();
            pq.pop();
            long long int b = pq.top();
            pq.pop();
            long long int sum = a + b;
            pq.push(sum);
            result += sum;
        }
        cout << result << '\n';
    }
     
    return 0;
}
