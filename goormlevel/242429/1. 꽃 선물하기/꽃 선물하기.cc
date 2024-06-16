#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--)
	{
		int a, b;
		cin >> a >> b;		
		if(a < b)
			cout << "Sunflower";
		else if(a > b)
			cout << "Rose";
		else
			cout << "Tulip";
		cout << '\n';
	}
	return 0;
}