#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
	int x;
	int y;
};
bool compareInfo(point &a, point &b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	int n;
	cin >> n;
	point arr[100000];
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr, arr+n, compareInfo);

	for (int i = 0; i < n; i++)
		cout << arr[i].x << " " << arr[i].y << "\n";

	return 0;
}