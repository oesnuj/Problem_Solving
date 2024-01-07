#include <iostream>
using namespace std;

int main()
{
    long long int N, M;
    cin >> N >> M;
    long long int popularityDifference = N-M;  
    //N과 M이 매우큰수라 '차'연산에서 범위를 넘을 수 있음(long long int 사용)
    if(popularityDifference < 0)
        cout << -popularityDifference <<endl;
    else
        cout << popularityDifference <<endl;
	return 0;
}

//다른 풀이
//c++에서는 abs함수가 절댓값을 반환해준다.
//로직은 위와 같지만 이제부터 abs함수로 절댓값을 나타내겠다.

//long long int popularityDifference = abs(N-M);
