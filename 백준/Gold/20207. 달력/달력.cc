#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[365] = {0};

struct EventPeriod
{
    int s, e;
};

bool compareInfo(EventPeriod a, EventPeriod b) {
    if (a.s == b.s) return a.e > b.e;
    return a.s < b.s;
}

int main()
{
    int N;
    cin >> N;
    vector <EventPeriod> v;
    while (N--)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({ s, e });
    }
    sort(v.begin(), v.end(), compareInfo);
    for (auto event : v)
    {
        for (int i = event.s - 1; i < event.e; i++) {
            arr[i]++;
        }
    }
    int result = 0;
    int current_height = 0;
    int current_width = 0;
    for (int i = 0; i < 365; i++) {
        if (arr[i] != 0) {
            current_width++;
            current_height = max(current_height, arr[i]);
        }
        
        if (arr[i + 1] == 0) {
            result += current_height * current_width;
            current_width = 0;
            current_height = 0;
        }
    }
    cout << result;
    return 0;
}