#include <iostream>
#include <chrono>
using namespace std;
#define int long long
int mod;//지금 체크하는 소인수 후보
int mul2(int p)
{
	int v = 1LL << p;
	v %= mod;
	//2^p를 소인수 후보로 나눴을 때 나머지
	return v - 1;//이 값이 0이면 소수가 아님
}
signed main()
{
	while (1)
	{
		int p;
		cout << "체크할 p를 입력하세요 : ";
		cin >> p;
		auto start = chrono::high_resolution_clock::now();//chrono=나노초 단위의 시간 계산
		int i;
		int isp = 1;
		for (i = 2; i < (1LL << p) - 1; i++)
		{
			mod = i;//현재 i를 체크하도록 설정
			//소수만 체크하지 않는 이유는 소수 계산에 시간이 걸리기 때문
			if (mul2(p) == 0)//mod로 나누어떨어짐 발견
			{
				isp = 0;
				cout << i << "로 나누어떨어짐\n";
			}
		}
		if (isp)
		{
			cout << (1LL << p) - 1 << "는 소수\n";
		}
		auto finish = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() / (1000000.0) << "밀리초\n";
	}
	
}//t