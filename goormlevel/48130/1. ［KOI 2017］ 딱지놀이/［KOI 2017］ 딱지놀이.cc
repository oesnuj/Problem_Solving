#include <iostream>
#include <vector>
using namespace std;

void input(int &num, vector <int> &v);
char compare(vector <int> &a, vector <int> &b);
void printWinner(char winner);

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		vector <int> a(4,0);
		vector <int> b(4,0);
		int numA, numB;
		cin >> numA;
		input(numA, a);
		cin >> numB;
		input(numB, b);
		printWinner(compare(a, b));
	}
	cout << endl;
	return 0;
}

void input(int &num, vector <int> &v)
{
	int type;
	for(int i = 0; i<num; i++)
	{
		cin >> type;
		v[type-1]++;
	}
}

char compare(vector <int> &a, vector <int> &b) 
{
	for(int i = 3; i>=0; i--)
	{
		if(a[i]>b[i]) return 'A';
		else if(a[i]<b[i]) return 'B';
	}
	return 'D';
}

void printWinner(char winner)
{
	cout << winner << '\n';
}
