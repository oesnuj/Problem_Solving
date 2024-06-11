#include <iostream>
using namespace std;

int main() {
    int k, d, a;
    char trash;
    cin>>k>>trash>>d>>trash>>a;
    if (k + a < d || d == 0)
        cout<<"hasu";
    else
        cout<<"gosu";
    return 0;
}
