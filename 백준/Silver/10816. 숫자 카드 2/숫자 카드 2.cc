#include <iostream>
using namespace std;

int main()
{
    //이진탐색 자꾸 오류나서 그냥 갯수를 생각하는 로직을 바꾸니 맞음
    ios::sync_with_stdio(0);  cin.tie(0); 
    int n; 
    cin >> n;
    int input_array[500000];
    int duplicate_input_array[20000005] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> input_array[i];
        duplicate_input_array[input_array[i] + 10000000] += 1;
    }

    int m; cin >> m;
    int search_array[500000];
    for (int i = 0; i < m; i++)
    {
        cin >> search_array[i];
        cout << duplicate_input_array[search_array[i] + 10000000] << " ";
    }
    return 0;
}