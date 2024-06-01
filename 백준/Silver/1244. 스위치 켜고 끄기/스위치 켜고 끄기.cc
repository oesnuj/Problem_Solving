#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v)
    {
        cin >> i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1) //남학생의 경우
        {
            int index = num;
            while (index <= n)
            {
                v[index-1] = !v[index-1];
                index += num;
            }
        }
        else //여학생의 경우
        {
            int index = num - 1;
            v[index] = !v[index];
            int i = 1;
            while (index - i >= 0 && index + i < n)
            {
                if (v[index - i] == v[index + i])
                {
                    v[index - i] = !v[index - i];
                    v[index + i] = !v[index + i];
                }
                else
                    break;
                i++;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && i % 20 == 0)
            cout << '\n';
        cout << v[i] << " ";
    }
    return 0;
}
 