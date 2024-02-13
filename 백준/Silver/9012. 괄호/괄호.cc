#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	stack <char> s;
	string ps;
	int n;
	
	cin >> n;
	while (n--)
	{
		bool checkVPS = true;
		cin >> ps;


		for (int i = 0; i < ps.size(); i++)
		{
			if ((s.empty() && ps[i] == ')')) 
				checkVPS = false;

			else
			{
				if (ps[i] == '(')
				{
					s.push(ps[i]);
				}
				else if (ps[i] == ')')
					s.pop();
			}

		}
		if (s.empty() == 1 && checkVPS == true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';


		while (!s.empty()) {
			s.pop();
		}

	}
	

	return 0;
}