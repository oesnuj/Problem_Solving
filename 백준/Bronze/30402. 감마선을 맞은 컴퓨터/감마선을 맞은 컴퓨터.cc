#include <iostream>
using namespace std;

int main()
{
    char arr[15][15];
    for(int i = 0; i< 15; i++)
    {
        for(int j = 0; j< 15; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'w')
            {
                cout << "chunbae";
                return 0;
            }  
            if(arr[i][j] == 'b')
            {
                cout << "nabi";
                return 0;
            } 
            if(arr[i][j] == 'g')
             {
                cout << "yeongcheol";
                return 0;
            } 
        }
    }
    return 0;
}