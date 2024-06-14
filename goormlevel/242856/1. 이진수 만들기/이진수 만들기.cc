#include <iostream>
#include <vector>
using namespace std;
int main() {
	int num;
	cin >> num;
	vector <int> v;
	
	while(num != 0)
	{
		v.push_back(num % 2);
		num /= 2;
	}
	
	for(int i = v.size() - 1; i >=0; i--)
	{
		cout << v[i];
	}	
	
	cout << endl;
	return 0;
}