#include <iostream>
using namespace std;

int main()
{
    int input;
    int sum_of_squares = 0;
    const int num = 5;
    for(int i =0; i<num; i++)
    {
        cin >> input;
        sum_of_squares += input * input;
    }
    sum_of_squares %= 10;
    cout << sum_of_squares;
    
	return 0;								
}