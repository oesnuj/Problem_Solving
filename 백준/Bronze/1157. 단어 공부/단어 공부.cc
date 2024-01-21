#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[26] = {0};
    char str[1000001];
    cin >> str;

    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
        size++;
    for (int i = 0; i < size; i++)
    {
        str[i] = toupper(str[i]); //65 ~ 90
        arr[str[i] - 65]++;
    }
    
    int first_max = 0; 
    int second_max = 0;
    int max_index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= first_max) {

            second_max = first_max;
            first_max = arr[i];
            max_index = i;

        }
            
    }

    if (first_max == second_max)
    {
        cout << "?";
        return 0;
    }
        
    cout << char(max_index + 65);
    return 0;
}
