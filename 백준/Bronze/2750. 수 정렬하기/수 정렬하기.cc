#include <iostream>
using namespace std;
int main()
{
    int n;
    int arr[1000];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    
    /*Bubble Sort
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }*/
    
    //selection Sort
    int min_index = 0;

    for(int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for(int j = i + 1; j<n; j++)
        {
            min_index = arr[min_index] > arr[j] ? j : min_index;
        }
        swap(arr[i], arr[min_index]);
    }


    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}