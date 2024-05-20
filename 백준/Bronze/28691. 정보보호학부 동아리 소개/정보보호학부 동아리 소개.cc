#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<char, string> clubMap = {
    {'M', "MatKor"},
    {'W', "WiCys"},
    {'C', "CyKor"},
    {'A', "AlKor"},
    {'$', "$clear"}
  };

  char firstLetter; cin >> firstLetter;

  cout << clubMap[firstLetter] << "\n";

  return 0;
}