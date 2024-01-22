#include <iostream>
#include <iomanip>  //setprecision(2) 둘째짜리 까지 출력
#include <cmath>    //reound 함수 사용
using namespace std;

int main()
{
	int n;
	cin >> n;
	string subject, grade;
	double credit;
	double score = 0;
	double sum_credit = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> subject >> credit  >> grade;
		if (grade == "A+")
			score += (4.3 * credit);
		else if (grade == "A0")
			score += (4.0 * credit);
		else if (grade == "A-")
			score += (3.7 * credit);
		else if (grade == "B+")
			score += (3.3 * credit);
		else if (grade == "B0")
			score += (3.0 * credit);
		else if (grade == "B-")
			score += (2.7 * credit);
		else if (grade == "C+")
			score += (2.3 * credit);
		else if (grade == "C0")
			score += (2.0 * credit);
		else if (grade == "C-")
			score += (1.7 * credit);
		else if (grade == "D+")
			score += (1.3 * credit);
		else if (grade == "D0")
			score += (1.0 * credit);
		else if (grade == "D-")
			score += (0.7 * credit);
		else
			score += (0.0 * credit);

		sum_credit += credit;
	}

	double result = score / sum_credit;
	cout << fixed << setprecision(2) << round(result * 100) / 100 << endl;
    return 0;
}
