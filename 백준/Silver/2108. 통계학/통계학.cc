#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int avr(double sum, int n);
int median(int* arr, int n);
int mode(int* arr, int n);
int range(int min, int max);

int main() {
	int n, input;
	double sum = 0;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		num[i] = input;
		sum += input;
	}
	sort(num, num + n);  
	int min_num = num[0];
	int max_num = num[n - 1];
	cout << avr(sum, n) << '\n' << median(num, n) << '\n' << mode(num, n) << '\n' << range(min_num, max_num);
	delete[] num;
}
int avr(double sum, int n) {
	return round(sum / n);
}
int median(int* arr, int n) {
	return arr[(n - 1) / 2];
}
int mode(int* arr, int n) {
	const int arr_size = 8001;
	int mode_arr[arr_size] = {0};
	int count = 0;
	for (int i = 0; i < n; i++)  //각 수를 인덱스로 하는 배열에 빈도수 저장
		mode_arr[arr[i] + 4000]++;
    
	int mode_max = 0;
	int result;
	for (int i = 0; i < arr_size; i++) //빈도수의 최댓값 구함
	 {
		 if (mode_arr[i] > mode_max)
			 mode_max = mode_arr[i];
	 }
	for (int i = 0; i < arr_size; i++) //빈도수 배열에서 최댓값과 같은 값을 출력, 만약 2개 이상이라면 두번째값을 구하고 break수행 
	{
		if (mode_max == mode_arr[i])
		{
			result = i - 4000;
			count++;
		}
		if (count == 2)
			break;

	}
	return result;
		
}
int range(int min, int max) {
	return max - min;
}