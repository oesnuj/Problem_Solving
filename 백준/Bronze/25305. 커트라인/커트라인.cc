#include <iostream>
using namespace std;

int main()
{
	int n, k;
	int score[1001];
	cin >> n >> k;
	int count = 1;
	int max_score = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if(score[j] > score[j + 1])
				swap(score[j], score[j + 1]);
		}
	}
	cout << score[n - k];

	return 0;
}
