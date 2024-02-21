#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int Prec(char c)  //연산자 우선순위 정의
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1; // '('는 우선순위가 아주 낮은 것으로 처리, ')' 닫는 괄호를 만날때까지 남겨두기 위함
}

int main()
{
    stack <char> s;
    queue <char> q;
    string infix;
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        q.push(infix[i]);
    }

    while (!q.empty())
    {
		char c = q.front();
		q.pop();
		if (c >= 'A' && c <= 'Z')
		{
			cout << c;
		}
		else if (c == '(')
		{
			s.push(c);
		}
		else if (c == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else //연산자가 나왔을때 스택에 있는 것보다  작거나 같으면 pop
		{
			while (!s.empty() && Prec(s.top()) >= Prec(c))
			{
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
    }
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
    return 0;
}