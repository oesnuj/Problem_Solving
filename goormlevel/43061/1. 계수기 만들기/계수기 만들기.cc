#include <iostream>
#include <vector>
using namespace std;

void inputVector(vector<int>& vec, int n);
void increaseNum(vector <int> &A, vector <int> &B, int n);

int main() {
	int n;
	cin >> n;

	vector<int> A, B;
	inputVector(A, n);
	inputVector(B, n);
	
	int k;
	cin >> k;
	for(int i =0; i< k; i++){
		increaseNum(A, B, n);
	}
	
	for(auto&i : B)
		cout << i;
}


void inputVector(vector<int>& vec, int n) {
    vec.resize(n);
    for (auto& i : vec) {
        cin >> i;
    }
}


void increaseNum(vector <int> &A, vector <int> &B, int n) {
	B[n-1]++;
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
}