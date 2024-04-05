#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n; //빌딩 개수 입력
	vector <int> v(n);
	stack <int> s;
	for (auto& i : v)
		cin >> i;   //각 빌딩 높이 입력
	long long int count = 0;
	for (const auto& height : v)
	{
		while (true)
		{
			if (s.empty()) //스택이 비었다면 push
			{
				s.push(height);
				break;
			}
			if (height < s.top()) //현재 top 보다 작은 빌딩이라면 (볼 수 있는 빌딩이라면)
			{
				count += s.size();
				s.push(height);
				break;
			}
			s.pop();
		}
	}
	cout << count;
	return 0;
}