#ifndef TILE_2133

#include <iostream>
#include <math.h>

using namespace std;
int N;
int dp[31];
int P[31];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	if (N % 2 != 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= 30; i++)
		P[i] = 2;
	P[2] = 3;
	dp[0] = 1;
	for (int i = 2; i <= N; i+=2)
	{
		for (int j = 1; j*2 <= i; j++)
			dp[i] += dp[i - 2 * j] * P[2*j];
	}

	cout << dp[N];
	return 0;
}

#endif // !TILE_2133

/*
dp를 이용해서, 처음엔 막 조합도 이용하면서 복잡하게 접근했다.
그러나 힌트를 보고 생각해보니,
값이 증가하면서 dp[i] = dp[i-2] * P[2] + dp[i-4] * P[4] + ..
이렇게 된다.
그리고 각 도형의 개수를 의미하는 P에서, 
2번(이땐 값이 3이 됨)을 제외하곤 다 양옆에 기둥이 있는 형태가 되어서 2가 된다.

이렇게 dp로 보다 쉽게, 시간복잡도도 O(N^2)로 구할 수 있다.
*/