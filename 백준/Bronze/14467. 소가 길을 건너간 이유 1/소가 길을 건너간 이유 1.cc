#include <iostream>
#include <vector>
using namespace std;

struct cow
{
    int name;
    int location;
};

int main() {
    vector <cow> v;

    int n;
    cin >> n;

    int cnt = 0;
    while (n--)
    {
        int cowNum, cowLoc;
        cin >> cowNum >> cowLoc;
        int i = 0;
        for (;i < v.size(); i++)
        {
            if (v[i].name == cowNum)
            {
                if (v[i].location != cowLoc)
                {
                    cnt++;
                    v[i].location = cowLoc;
                }
                break;
            }
        }
        if (i == v.size())
            v.push_back({ cowNum, cowLoc });
    }
    cout << cnt;
    return 0;
}