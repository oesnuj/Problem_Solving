#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x;
	int y;
};

bool compareInfo(point& a, point& b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main() {
	int n;
	cin >> n;
	point*p = new point[n];
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;

	sort(p, p + n, compareInfo);
	// 구조체와 같이 자료형이 복잡한 경우 정렬시 비교조건을 붙여야한다.

	for (int i = 0; i < n; i++)
		cout << p[i].x << " " << p[i].y << '\n';

	delete[] p;
	return 0;
}