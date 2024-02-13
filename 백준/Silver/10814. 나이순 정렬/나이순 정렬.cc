#include <iostream>
#include <algorithm>
using namespace std;

struct info {
	int age;
	string name;
};

bool compareInfo(const info& a, const info& b) {
	// 나이를 기준으로 정렬
	return a.age < b.age;
}

int main() {
	int n;
	cin >> n;
	info *users = new info[n];
	for (int i = 0; i < n; i++)
		cin >> users[i].age >> users[i].name;

	stable_sort(users, users + n, compareInfo); 
	//1. 구조체와 같이 자료형이 복잡한 경우 정렬시 비교조건을 붙여야한다.
	//2. stable_sort는 퀵sort와 다르게 동일한 키 값을 가지는 요소들 간의 순서가 유지된다.

	for (int i = 0; i < n; i++)
		cout << users[i].age << " " << users[i].name << '\n';

	delete[] users;
	return 0;
}
