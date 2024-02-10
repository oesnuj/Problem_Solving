#include <iostream>
#include <algorithm>
using namespace std;

bool BinarySearch(int* arr, int n, int x);

int main()
{
    const int MAX_SIZE = 100000;
    int input_array[MAX_SIZE];
    int search_array[MAX_SIZE];
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input_array[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> search_array[i];
    
    sort(input_array, input_array + n); //이진 탐색을 위해 정렬
    
    for (int i = 0; i < m; i++)
        cout << BinarySearch(input_array, n, search_array[i]) << '\n';

    return 0;
}

bool BinarySearch(int* arr, int n, int x) //이진 탐색 수행
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (x > arr[middle])
            left = middle + 1;
        else if (x < arr[middle])
            right = middle - 1;
        else
            return true;
    }
    return false;
}