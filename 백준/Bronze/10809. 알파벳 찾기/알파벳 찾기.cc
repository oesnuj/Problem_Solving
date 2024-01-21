#include <iostream>
using namespace std;

int main()
{
    int arr[26] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    char str[101];
    cin >> str;

    int size = 0;
    for (int i = 0; str[i] != '\0'; i++) //문자열 길이 측정
        size++;

    for (int i = 0; i < size; i++) //알바펫 순서칸의 배열에 순서대로 값 입력
        if(arr[str[i] - 97] == -1) //처음 등장한 알파벳인 경우에만
            arr[str[i] - 97] = i; 
    
    for (int i = 0; i < 26; i++) //출력
        cout << arr[i] << " ";

    return 0;
}
