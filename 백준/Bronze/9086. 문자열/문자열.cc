#include <iostream>
using namespace std;
int main()
{
    const int str_size = 1001; //'\0'도 고려
    char str[str_size];
    int n;
    cin >> n;
    int size = 0;
    for (int T = 0; T < n; T++)
    {
        int input;
        cin >> str;
        
        int size =0;
        for (int i = 0; str[i] != '\0'; i++) 
            size++;
        cout << str[0] << str[size-1] << endl;
    }
    return 0;
}