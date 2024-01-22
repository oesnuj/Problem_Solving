#include <iostream>
using namespace std;

int main()
{
	string subject, grade;
	double credit;
	double score = 0;
	double sum_credit = 0;
	for (int i = 0; i < 20; i++)
	{
		cin >> subject >> credit >> grade;
		if (grade == "F")
		{
			score += (0.0 * credit);
			sum_credit += credit;
		}
		else if (grade == "P")
			continue;
		else
		{
			double gradValue = (grade[1] == '+') ? (69 - grade[0] + 0.5) : (69 - grade[0]);
			score += credit * gradValue;
			sum_credit += credit;

		}
	}
	double result = score / sum_credit;
	cout << result;
	return 0;
}