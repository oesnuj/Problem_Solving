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
		int input;
		cin >> input;
		if (input == 1)
		{
			int num;
			cin >> num;
			d.push_front(num);
		}

		else if (input == 2)
		{
			int num;
			cin >> num;
			d.push_back(num);
		}

		else if (input == 3)
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.front() << '\n';
			d.pop_front();
		}

		else if (input == 4)
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.back() << '\n';
			d.pop_back();
		}

		else if (input == 5)
		{
			cout << d.size() << '\n';
		}

		else if (input == 6)
		{
			cout << d.empty() << '\n';
		}
		

		else if (input == 7)
		{
			if (d.empty())
			{
				cout << "-1" << '\n';
				continue;
			}
			cout << d.front() << '\n';
		}

		else if (input == 8)
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