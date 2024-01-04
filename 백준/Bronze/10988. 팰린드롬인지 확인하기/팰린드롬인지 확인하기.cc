#include <iostream>

using namespace std;

int main() {

  string s;
  cin >> s;

  for(int i = 0; i <= s.length() / 2; i++) {
    if(s[i] != s[s.length() - i - 1]) {
      cout << 0;
      return 0;
    }
  }

  cout << 1;

  return 0;
}