#include <iostream>
#include <stack>
#include <cctype> //issspace : 공백을 만나면 0 반환
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack <char> stack;
	int t;
	cin >> t;
	cin.ignore(); //t 입력이후 버퍼에 남아있는 \n 비우기
	char word;
	
	while (t--)
	{
		while ((word = cin.get()) != '\n')
		{
			if (isspace(word))
			{
				while (!stack.empty())
				{
					cout << stack.top();
					stack.pop();
				}
				cout << " ";
			}
			else {
				stack.push(word);
			}
				
		}
		while (!stack.empty())
		{
			cout << stack.top();
			stack.pop();
		}
		cout << '\n';
	}
	return 0;
}