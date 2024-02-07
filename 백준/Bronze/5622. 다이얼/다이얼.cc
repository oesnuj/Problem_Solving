#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int sum = 0;
    //내가 처음 접근한 풀이
    //for (int i = 0; i < str.length(); i++) {
    //    if (64 < str[i] && str[i] < 68) // A B C
    //        sum += 3;
    //    else if (67 < str[i] && str[i] < 71) // D E F
    //        sum += 4;
    //    else if (70 < str[i] && str[i] < 74) // G H I
    //        sum += 5;
    //    else if (73 < str[i] && str[i] < 77) // J K L
    //        sum += 6;
    //    else if (76 < str[i] && str[i] < 80) // M N O
    //        sum += 7;
    //    else if (79 < str[i] && str[i] < 84) // P Q R S
    //        sum += 8;
    //    else if (83 < str[i] && str[i] < 87) // T U V
    //        sum += 9;
    //    else // W X Y Z
    //        sum += 10;
    //}


    //풀이 2 - 모든 알파벳에 대응되는 숫자 배열을 만들고 아스키코드를 사용한다.
    int num[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
    for (int i = 0; i < str.length(); i++) {
        sum += num[str[i] - 65];
    }

    cout << sum;
    return 0;
}
