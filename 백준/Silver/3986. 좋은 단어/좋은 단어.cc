#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		stack <char>s;
		string str;
		cin >> str;
		//top과 같으면 pop
		for (int i = 0; i < str.length(); i++)
		{
			if (s.empty()) //비어있으면 무조건 push
			{
				s.push(str[i]);
				continue;
			}

			//top과 다음 문자 비교 수행
			if (s.top() == str[i]) //같으면 pop
				s.pop();
			else  //다르면 push
				s.push(str[i]);
		}
		if (s.empty()) //끝나고 비어있으면 좋은 단어
			cnt++;
	}
	cout << cnt;
	return 0;
}