#include <iostream>
using namespace std;

int main()
{
    int a,b;
    int j =0;
    int count =0;
    cin >> a >> b;
    int arr[1000];
    for(int i =1; i<=a;i++)
    {
        if(a%i==0)
        {
            arr[j++]=i;
            count++;
        }
    }
    if(b>count)
        cout << "0";
    else
        cout << arr[b-1];
   return 0;
}