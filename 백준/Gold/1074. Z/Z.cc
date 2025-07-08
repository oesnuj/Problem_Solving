#include <iostream>
using namespace std;

int Z(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);  // 2^(n-1)
	int size = half * half;

    if (r < half && c < half) 
		return Z(n - 1, r, c);

    else if (r < half && c >= half) 
		return size + Z(n - 1, r, c - half);

    else if (r >= half && c < half) 
		return size * 2 + Z(n - 1, r - half, c);

    else 
		return size * 3 + Z(n - 1, r - half, c - half);
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
	return 0;
}
