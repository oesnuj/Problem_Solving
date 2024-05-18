#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];
    for (int i = 0; i < 3; i++){
        cin >> arr[i];
    }
    sort(arr, arr + 3);
    char target;
    for (int i = 0; i < 3; i++){
        cin >> target;
        cout << arr[target - 'A'] << " ";
    }
    return 0;
}