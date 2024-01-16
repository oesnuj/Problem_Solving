#include <iostream>
using namespace std;
int main()
{
    const int size = 5;
    int arr[size];
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }   
    
    //Bubble Sort
    for(int i =0; i<size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }

    int median= arr[size/2];
    int avr = sum/size;
    cout << avr << endl<< median;
    return 0;
}