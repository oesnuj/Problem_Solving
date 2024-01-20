#include <iostream>
using namespace std;
int main()
{
    const int str_size = 1000001; //'\0'도 고려
    char str[str_size];
    cin.getline(str, str_size);
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
	    size++;

    int count = 0;
    for(int i =0; i<size; i++)
    {
        if(str[0] == ' ' && size==1){ //공백만 입력한 경우
            cout << 0;
            return 0;
        }
            
        if(str[i] == ' ' && (i == 0 || i == size - 1)) //단어 갯수 세기
            continue;
        if(str[i]==' ')
            count++;
            
    }
    cout << count + 1;
    return 0;
}