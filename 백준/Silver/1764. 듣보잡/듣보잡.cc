#include <iostream>
#include <string>
#include <vector>
#include <algorithm>;
using namespace std;


bool binarySearch(vector <string> &v, string str)
{
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (str > v[middle])
        {
            left = middle + 1;
        }
        else if (str < v[middle])
        {
            right = middle - 1;
        }
        else
            return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <string> v(n);
    for (auto& i : v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    vector <string> result;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        if (binarySearch(v, word)){
            result.push_back(word);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (const auto& word : result) {
        cout << word << "\n";
    }
    return 0;        
}