#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;
    double k = w * h / 2.0;
    cout << fixed << setprecision(1) << k;
    
    return 0;
}