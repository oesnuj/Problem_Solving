#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	double salt = n * 0.07; //소금양 추출
	double water = n + m; //젠체 소금물 g구하기
	 double concentration = (salt / water) * 100.0;
	concentration = floor(concentration * 100) / 100.0;
	printf("%.2f", concentration);
	return 0;
} 
