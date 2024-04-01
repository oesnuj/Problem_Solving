#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[1000000];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++){
		cout << arr[i] << '\n';
	}
	return 0;
}