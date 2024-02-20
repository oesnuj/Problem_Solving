#include <iostream>
#include <deque>
using namespace std;

struct balloon{
	int index;
	int	paper_num;
	
};

int main()
{
	ios::sync_with_stdio(0);  cin.tie(0);

	deque<balloon> d;
	balloon b;
	int n;
	cin >> n;

	int result[1005]; int k = 0;
	for(int i = 0; i<n; i++) //입력
	{
		cin >> b.paper_num;
		b.index = i + 1;
		d.push_back({ b.index, b.paper_num });
	}

	int currentPaperNum = d.front().paper_num; //첫번째 풍선 먼저 터트린다.
	result[0] = d.front().index;
	d.pop_front();

	while (d.size() != 1)
	{
		//음수라면 back부터 paper_num만큼 push_front후 back 풍선 터트리고 pop_back
		if(currentPaperNum < 0)
		{ 
			for (int i = 1; i < -(currentPaperNum); i++)
			{
				d.push_front(d.back());
				d.pop_back();
			}
			result[++k] = d.back().index;
			currentPaperNum = d.back().paper_num;
			d.pop_back();
		}

		//양수라면 front부터 paper_num만큼 push_back후 front 풍선 터트리고 pop_front 수행
		else
		{
			for (int i = 1; i < currentPaperNum ; i++)
			{
				d.push_back(d.front());
				d.pop_front();
			} 
			result[++k] = d.front().index;
			currentPaperNum = d.front().paper_num;
			d.pop_front();
		}
	}
    
	result[++k] = d.front().index;
	for(int i = 0; i < n; i++)
		cout << result[i] << " ";
    
	return 0;
}