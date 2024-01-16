#include <iostream>
using namespace std;
int main()
{
    const int size = 10;
    int arr[size];
    int count = 1;
    //입력시 나머지 값으로 배열생성
    for(int i = 0; i < size; i++){ 
        cin >> arr[i];
        arr[i] %= 42;
    }


    //나머지 배열 정렬수행
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j< size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }

    //정렬된 배열에서 중복된 요소는 제외하고 카운트
    for(int i = 0; i < size - 1; i++){
        if(arr[i] != arr[i+1]){
            count++;
        }
    }
    cout << count;
    return 0;
}