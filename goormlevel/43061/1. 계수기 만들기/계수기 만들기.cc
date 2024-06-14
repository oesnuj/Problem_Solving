#include <iostream>
#include <vector>
using namespace std;

void checkNum(vector <int> &A, vector <int> &B, int n);

int main() {
	int n;
	cin >> n;
	vector <int> A(n);
	for(auto &i : A)
	{
		cin >> i;
	}
	vector <int> B(n); 
	for(auto &i : B)
	{
		cin >> i;	
	}
	
	int k;
	cin >> k;
	for(int i =0; i< k; i++)
	{
		B[n-1]++; //1씩 증가시킨다.
		checkNum(A, B, n);

	}
	for(auto&i : B)
		cout << i;
}


void checkNum(vector <int> &A, vector <int> &B, int n)
{
	for(int i = n-1; i >= 0; i--)
	{
		if(B[i] > A[i])
		{
			B[i] = 0;
			if(i != 0)
				B[i - 1]++;
		}
		else
			return;
	}
	return;
}