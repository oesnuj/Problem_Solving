#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>


int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	unsigned long long a;
	unsigned long long b;
	unsigned long long c;


	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	unsigned long long abc = a * b * c;
	std::string tempStr = std::to_string(abc);

	int32_t numArray[10] = { 0,0,0,0,0,0,0,0,0,0 };
	while (true)
	{
		if (tempStr.empty())
		{
			break;
		}

		const char tempChar = tempStr.back();
		const int tempDigit = tempChar - '0';
		numArray[tempDigit] += 1;
		tempStr.pop_back();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << numArray[i] << "\n";
	}
}