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
		
		//두번째 풀이 아스키코드 활용
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

		//첫번째 풀이 : 그냥 다 조건 걸기
		/*for (int i = 0; i < 20; i++)
		{
			cin >> subject >> credit >> grade;
			if (grade == "A+")
				score += (4.5 * credit);
			else if (grade == "A0")
				score += (4.0 * credit);
			else if (grade == "B+")
				score += (3.5 * credit);
			else if (grade == "B0")
				score += (3.0 * credit);
			else if (grade == "C+")
				score += (2.5 * credit);
			else if (grade == "C0")
				score += (2.0 * credit);
			else if (grade == "D+")
				score += (1.5 * credit);
			else if (grade == "D0")
				score += (1.0 * credit);
			else if (grade == "P")
				continue;
			else
				score += (0.0 * credit);

			sum_credit += credit;
		}*/

	}
	double result = score / sum_credit;
	cout << result;
	return 0;
}
