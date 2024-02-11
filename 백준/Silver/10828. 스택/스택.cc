#include <iostream>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack <int> stack;
	int N;
	cin >> N;

	string str;
	while (N--)
	{
		int x;
		cin >> str;
		if (str == "push")
		{
			cin >> x;
			stack.push(x);
		}

		else if (str == "pop")
		{
			if (!stack.empty())
			{
				cout << stack.top() << '\n';
				stack.pop();
			}
			else
				cout << -1 << '\n';
		}

		else if (str == "size")
			cout << stack.size() << '\n';

		else if (str == "empty")
			cout << stack.empty() << '\n';

		else if (str == "top")
		{
			if (!stack.empty())
				cout << stack.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}