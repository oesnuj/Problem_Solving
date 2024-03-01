#include <iostream>
#include <algorithm>
using namespace std;

int findindex(long long int* arr, int n, long long int target) //이분탐색
{
	int left = 0;
	int right = n-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < target)
			left = mid + 1;
		else if (arr[mid] > target)
			right = mid - 1;
		else
			return mid;
	}		
	return 0;
}

int main()
{
	int n;
	cin >> n;
	long long int num[1000000];
	long long int sortNum[1000000];
	long long int result[1000000];
	
	for (int i = 0; i < n; i++) //값 입력받음
	{
		cin >> num[i];
		sortNum[i] = num[i];
	}

	sort(sortNum, sortNum + n); //정렬 수행

	result[0] = sortNum[0]; //중복 제거 수행
	int resultSize = 1;  
	int j = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (sortNum[i] != sortNum[i + 1])
		{
			result[j++] = sortNum[i + 1];
			resultSize++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << findindex(result, resultSize, num[i]) << " ";

	return 0;
}