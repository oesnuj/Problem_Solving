#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> d;
	int n;
	cin >> n;
	while (n--)
	{
		string input;
		cin >> input;
		if (input == "push_front")
		{
			int num;
			cin >> num;
			d.push_front(num);
		}

		else if (input == "push_back")
		{
			int num;
			cin >> num;
			d.push_back(num);
		}

		else if (input == "pop_front")
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.front() << '\n';
			d.pop_front();
		}

		else if (input == "pop_back")
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.back() << '\n';
			d.pop_back();
		}

		else if (input == "size")
		{
			cout << d.size() << '\n';
		}

		else if (input == "empty")
		{
			cout << d.empty() << '\n';
		}
		

		else if (input == "front")
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.front() << '\n';
		}

		else if (input == "back")
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.back() << '\n';
		}
	}
	return 0;
}