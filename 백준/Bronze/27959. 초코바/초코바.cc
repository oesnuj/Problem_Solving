#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n * 100 >= m)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}