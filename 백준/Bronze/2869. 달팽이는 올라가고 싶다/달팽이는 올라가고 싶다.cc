#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, v;
    cin >> a >> b >> v;
    int count = 1;

    //방정식 풀이 마지막은 낮에 오르니까
    //정상에서 v -a 한값에 방정식을 풀면된다.
    int divisor = v - a; //
    int denominator = a - b;
    if (a == v)
    {
        cout << count;
        return 0;
    }
    count += (divisor / denominator); //나누어 떨어지지 않는다면 하루 더 추가한다.
    if (divisor % denominator != 0)
        count++;

    cout << count;
    /*
    처음 풀이 <- 0.25초만에 못푼다.
    입력값에 따라 시간이 무한하게 걸릴 수도 있음
    입력받은 a, b로 v에 도달할때 까지 무한하게 계산해야함
    따라서 v를 이용해서 날짜를 구하는 로직을 바꾸었어야함

        while (1) { //사용된 숫자의 인덱스 칸이 1씩증가
        count++; //하루의 시작
        sum += a; //오르는 낮
        if (sum >= v) //올라서 정상에 도달했다면
        {
            cout << count;
            break;
        }
        sum -= b; //미끄러지는 밤
    }*/

    return 0;
}
