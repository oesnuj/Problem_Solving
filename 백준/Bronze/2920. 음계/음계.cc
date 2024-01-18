#include <iostream>
using namespace std;

int checkOrder(int * arr, int n)
{
    bool ascend = false;
    bool descend = false;
    for(int i =0; i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            descend = true;
        }
        else if(arr[i]<arr[i+1])
        {
            ascend = true;
        }   
    }    
    if(ascend == descend){
        cout << "mixed" <<endl;
        return 0;
    }
    if(ascend == true)
        cout << "ascending" << endl;
    if(descend == true)
        cout << "descending" << endl;
    return 0;
}

int main()
{
    int arr[8];
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n; i++)
    {
        cin >> arr[i];
    }
    checkOrder(arr,n);
   
   return 0;
}
