#include <iostream>
using namespace std;
int main()
{
    const int str_size = 101; //null도 고려
    char str[str_size];
    int n;
    cin >> n;
    
    int size = 0;
    for (int T = 0; T<n; T++)
    {
        int input;
        char str[21];
        cin >> input >> str;
        
        int size =0 ;
        for (int i = 0; str[i] != '\0'; i++) 
            size++;

        for(int j =0; j<size; j++) //input만큼
        {
            for(int k =0; k<input; k++)
                cout << str[j];
        }
        cout << endl;
    }
    return 0;
}