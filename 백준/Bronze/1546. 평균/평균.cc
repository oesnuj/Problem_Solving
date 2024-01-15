#include <iostream>
using namespace std;

int main()
{
    int n;
    double arr[1000];
    int max_num = 0;
    double sum = 0;

    cin >> n;  
    for (int i = 0; i < n; i++) //점수입력받고 최댓값 구하기
    {
        cin >> arr[i];
        max_num = arr[i] > max_num ? arr[i] : max_num;
    }

    for (int k = 0; k < n; k++) //최댓값을 통해 새로운 점수로 조작하기
    {
        arr[k] = (arr[k] / max_num) * 100;
    }

    for (int i = 0; i < n; i++) //새로운 평균 구하기
    {
        sum += arr[i];
    }
    double avr = sum / n;
    cout << avr << endl;

    return 0;
}
