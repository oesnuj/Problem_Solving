#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[365] = {0};
struct EventPeriod
{
    int s, e;
};

int main()
{
    int N;
    cin >> N;
    vector <EventPeriod> v(N);
    for(int i = 0; i < N; i++)
    {
        int s, e;
        cin >> v[i].s >> v[i].e;
    }

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