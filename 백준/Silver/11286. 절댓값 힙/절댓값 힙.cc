#include <iostream>
#include <queue>
using namespace std;

struct compare{ // 정렬 기준 바꾸는 함수
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b; // 절대값이 같은 경우 가장 작은 원소로
        return abs(a) > abs(b); // 절대값이 작은 원소로
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue <int, vector<int>, compare> q;

    int n;
    cin >> n;
    while (n--)
    {
        int x;
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