#include <iostream>
#include <stack>
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

	for (int i = 0; i < n; i++)
		cout << users[i].age << " " << users[i].name << '\n';

	delete[] users;

	return 0;
}