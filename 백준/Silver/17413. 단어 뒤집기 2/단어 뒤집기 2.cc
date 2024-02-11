#include <iostream>
#include <stack>
#include <string> 
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack <char> s;
	string sentence;
	bool tagCheck = false;


	getline(cin, sentence);
	sentence += ' '; //마지막에 공백 포함시켜 마지막 단어도 pop 되게 한다.
	for (int i = 0; i < sentence.size(); i++)
	{
		if (tagCheck)
		{
			cout << sentence[i];
			if (sentence[i] == '>')
				tagCheck = false;
			continue;
		}

		if (sentence[i] == ' ') //공백 전에 pop
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << ' ';
		}
		else if (sentence[i] == '<')
		{
			tagCheck = true;
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			cout << sentence[i];
		}
		else
			s.push(sentence[i]);
	}
	return 0;
}