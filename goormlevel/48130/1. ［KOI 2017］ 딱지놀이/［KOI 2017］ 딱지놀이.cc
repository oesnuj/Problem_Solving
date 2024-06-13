#include <iostream>
#include <vector>
using namespace std;

void input(int &num, vector <int> &v);
char compare(vector <int> &a, vector <int> &b);
void printWinner(char &winner);

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
		char winner = compare(a, b);
		printWinner(winner);
	}
	cout << endl;
	return 0;
}

void input(int &num, vector <int> &v) //입력 숫자에 맞게 딱지 타입과 그 갯수를 name 벡터에 저장한다.
{
	for(int i = 0; i<num; i++)
	{
		int type;
		cin >> type;
		v[type-1]++;
	}
}

char compare(vector <int> &a, vector <int> &b) //a, b 비교 후 이긴사람을 출력해준다.
{
	for(int i = 3; i>=0; i--)
	{
		if(a[i]>b[i])
			return 'A';
		else if(a[i]<b[i])
			return 'B';
		else
			if(i == 0)
				return 'D';
	}
}

void printWinner(char &winner)
{
	if(winner == 'A')
		cout << "A\n";
	else if(winner == 'B')
		cout << "B\n";
	else if(winner == 'D')
		cout << "D\n";
}
