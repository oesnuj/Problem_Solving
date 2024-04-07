#include <iostream>
#include <vector>
using namespace std;

struct MyStruct
{
	int index;
	int a;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <MyStruct> v(n);
	vector <int> result(n, -1);

	int k = 0;
	for (int i = 0; i < n; i++)
	{
		v[i].index = i; //각 위치의 오큰수를 출력해야해서 각 위치의 인덱스를 저장한다.
		cin >> v[i].a; //수열 A의 구성원을 입력받음
	}
	//스택의 구성을 항상 내림차순으로 정렬한다.
	// 내림차순을 깨는 수(i)가 나온다면 그 수가 내림차순 위치에 들어갈때 까지 스택 원소 pop
	//pop된 원소의 오큰수가 바로 i 이다.
	vector <MyStruct> s;
	for (int i = 0; i<n; i++) 
	{
		while (!s.empty() && s.back().a < v[i].a) //자신(s.top)보다 크고 가장 먼저 나온 오큰수
		{
			result[s.back().index] = v[i].a; //s.top()의 오큰수(s.top의 위치에 맞게)결과 배열에 오큰수 넣는다.
			s.pop_back(); 
			//v[i].a가 누군가의 오큰수인 경우(스택이 비거나, 자신보다 작은 s.top을 만날때까지)
		}
		s.push_back(v[i]); //더이상 스택에 나를 오큰수로 여기는 수가 없다면 push해준다.
	}
	for (const auto& i : result)
		cout << i << " ";
	return 0;
}