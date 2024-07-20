#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calc(char c) {
    if (c == 'H')
        return 1;
    else if (c == 'C')
        return 12;
    else if (c == 'O')
        return 16;
}

int main() {
    string str;
    cin >> str;

    vector <int> s;
    for (const auto& c : str) {
        if (c == 'H' || c == 'O' || c == 'C') {
            s.push_back(calc(c));
        }
        else if (c == '(')
        {
            s.push_back(-1);
        }
        else if (c == ')') {
            int temp = 0;
            while (s.back() != -1) {
                temp += s.back();
                s.pop_back();
            }
            s.pop_back(); //여는 괄호 지워주기
            s.push_back(temp);
        }
        else
        {
            int temp = s.back() * (c - '0');
            s.pop_back();
            s.push_back(temp);
        }
    }
    
    int result = 0;
    while (!s.empty()) {
        result += s.back();
        s.pop_back();
    }
    cout << result;
    return 0;
}