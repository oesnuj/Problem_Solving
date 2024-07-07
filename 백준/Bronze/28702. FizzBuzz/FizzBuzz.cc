#include <iostream>
#include <string>
using namespace std;

void printResult(int n) {
    if (n % 3 == 0 && n % 5 == 0) cout << "FizzBuzz";
    else if (n % 3 == 0 && n % 5 != 0) cout << "Fizz";
    else if (n % 5 == 0 && n % 3 != 0) cout << "Buzz";
    else cout << n;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int result = 0;
    if (a != "Fizz" && a != "Buzz" && a != "FizzBuzz")  result = stoi(a) + 3;
    else if (b != "Fizz" && b != "Buzz" && b != "FizzBuzz") result = stoi(b) + 2;
    else result = stoi(c) + 1;

    printResult(result);
    return 0;
}

