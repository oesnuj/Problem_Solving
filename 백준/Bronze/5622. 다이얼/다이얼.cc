#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int sum = 0;

    for (int i = 0; i < str.length(); i++) {
        if (64 < str[i] && str[i] < 68) // A B C
            sum += 3;
        else if (67 < str[i] && str[i] < 71) // D E F
            sum += 4;
        else if (70 < str[i] && str[i] < 74) // G H I
            sum += 5;
        else if (73 < str[i] && str[i] < 77) // J K L
            sum += 6;
        else if (76 < str[i] && str[i] < 80) // M N O
            sum += 7;
        else if (79 < str[i] && str[i] < 84) // P Q R S
            sum += 8;
        else if (83 < str[i] && str[i] < 87) // T U V
            sum += 9;
        else // W X Y Z
            sum += 10;
    }

    cout << sum;
    return 0;
}
