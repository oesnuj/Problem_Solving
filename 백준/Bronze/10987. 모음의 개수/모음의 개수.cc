#include <iostream>
using namespace std;

int main()
{
	char words[101];
	cin >> words;
	int size = 0;
	int count = 0;
	for (int i = 0; words[i] != '\0'; i++)
		size++;
	for (int i = 0; i < size; i++)
	{
		if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'o' || words[i] == 'u')
			count++;
	}
	cout << count;
	return 0;
}
