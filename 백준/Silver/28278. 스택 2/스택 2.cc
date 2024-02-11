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
	char input;

	while (N--)
	{
		int x;
		cin >> input;
		if (input == '1')
		{
			cin >> x;
			stack.push(x);
		}

		else if (input == '2')
		{
			if (!stack.empty())
			{
				cout << stack.top() << '\n';
				stack.pop();
			}
			else
				cout << -1 << '\n';
		}

		else if (input == '3')
			cout << stack.size() << '\n';

		else if (input == '4')
			cout << stack.empty() << '\n';

		else if (input == '5')
		{
			if (!stack.empty())
				cout << stack.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}
