#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	deque <int> d;
	ios::sync_with_stdio(0);  cin.tie(0);
	int n, m; 
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
	{
		d.push_back(i);
	}

	int *num = new int [m];
	for (int i = 0; i < m; i++)
		cin >> num[i];

	int min_cnt = 0;
	int index = 0;

	while (index != m)
	{
		int cnt_2 = 0;
		int cnt_3 = 0;
		while(1) //2번 연산
		{
			if (d.front() == num[index])
				break;
			d.push_back(d.front());
			d.pop_front();
			cnt_2++;
		}
		for (int i = 0; i < cnt_2; i++) //다시 원상복구
		{
			d.push_front(d.back());
			d.pop_back();
		}
		while (1) // 3번연산
		{
			if (d.front() == num[index])
				break;
			d.push_front(d.back());
			d.pop_back();
			cnt_3++;
		}
		min_cnt += min(cnt_2, cnt_3); //2번, 3번 연산중에 최솟값 구하기
		if (cnt_2 < cnt_3) //3번 연산이 적다면 그냥 그대로 넘어가기 
		{
			for (int i = 0; i < cnt_3; i++) //2번 연산이 최솟값이라면 다시 원상복구
			{
				d.push_back(d.front());
				d.pop_front();
			}
			while (d.front() != num[index]) //2번연산
			{
				d.push_back(d.front());
				d.pop_front();
			}
		}
		index++;
		d.pop_front();
	}
	cout << min_cnt;
}