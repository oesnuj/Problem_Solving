#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int arr[26]{0};
	while (true)
	{
		string word;
		cin >> word;
		for (int i = 0; i < word.length(); i++)
		{
			arr[word[i] - 'a']++;
		}
		if (cin.eof())
			break;
	}
	int max = 0;
	vector <int> v;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			v.clear();
			v.push_back(i);
		}
		else if (arr[i] == max)
		{
			v.push_back(i);
		}
	}
	for (const auto& i : v)
		cout << char(i+'a');
	return 0;
}