#include <iostream>
#include <stack>
using namespace std;

struct tower {
	int height;
	int index;
};

int main() {
	stack <tower> s;
	tower t;
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int* result = new int[n]();
	int count = 0;

	t.height = arr[0];
	t.index = 1;
	s.push(t);

	for (int i = 1; i < n; i++)
	{
		t.height = arr[i];
		t.index = i+1;
	
		while (1)
		{
			if (s.empty()) //탈출 조건 1. 높은 탑이 없어 새로운 탑을 push 후 탈출
			{
				result[i] = 0;
				s.push(t);
				break;
			}

			else
			{
				if (t.height >= s.top().height)
					s.pop();

				else if (t.height < s.top().height) //탈출 조건 2. 높은 탑이 있어 해당 탑 번호 저장, 현재 탑 정보 push 후 탈출
				{
					result[i] = s.top().index;
					s.push(t);
					break;
				}
			}
		}
			
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	return 0;
}