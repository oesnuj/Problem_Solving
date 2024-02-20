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
	/*첫번째 풀이 -> 더 최적화 시킬 방법을 찾아봄
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
	*/

	//두번째 풀이
	//1. currentPaperNum을 front에서만 뽑아오게 바꾸어 코드를 줄일 수 있음 
	// <- 첫번째 풍선도 반복문 안에서 다 처리함
	//2. 출력값을 배열에 굳이 넣지않고 cout으로 outstream에 쌓아 놓는다.
	while (1)
	{
		int currentPaperNum = d.front().paper_num;
		cout << d.front().index << " ";
		d.pop_front();
		if (d.empty())
			break;

		//음수라면 back부터 paper_num + 1만큼 push_front후 front 풍선 터트리고 pop_front 수행
		if (currentPaperNum < 0)
		{
			for (int i = 1; i < -(currentPaperNum) + 1; i++)
			//back을 하나 더 front로 옮기면 currentPaperNum 정보는 무조건 front에서 뽑아 올 수 있음 
			{
				d.push_front(d.back());
				d.pop_back();
			}
		}

		//양수라면 front부터 paper_num만큼 push_back후 front 풍선 터트리고 pop_front 수행
		else
		{
			for (int i = 1; i < currentPaperNum; i++)
			{
				d.push_back(d.front());
				d.pop_front();
			}
		}
	}
	return 0;
}
