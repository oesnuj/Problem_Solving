#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    priority_queue <int, vector<int>, greater<int>> pq;
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int sum = 0;
    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();                                                                                   
        int b = pq.top();
        pq.pop();
        int com = a + b;
        pq.push(com);
        sum += com;
    }
    cout << sum;
    return 0;
}