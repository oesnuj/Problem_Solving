#include <iostream>
using namespace std;

int main()
{
    const int totalStudents = 31;
    int studentNumbers[totalStudents] = {0};
    int input;

    for (int i = 0; i < totalStudents - 3; i++)
    {
        cin >> input;
        studentNumbers[input] = 1;
    }

    for (int i = 1; i <= totalStudents -1; i++)
    {
        if (studentNumbers[i] == 0)
            cout << i << endl;
    }

    return 0;
}
