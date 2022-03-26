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
dp�� �̿��ؼ�, ó���� �� ���յ� �̿��ϸ鼭 �����ϰ� �����ߴ�.
�׷��� ��Ʈ�� ���� �����غ���,
���� �����ϸ鼭 dp[i] = dp[i-2] * P[2] + dp[i-4] * P[4] + ..
�̷��� �ȴ�.
�׸��� �� ������ ������ �ǹ��ϴ� P����, 
2��(�̶� ���� 3�� ��)�� �����ϰ� �� �翷�� ����� �ִ� ���°� �Ǿ 2�� �ȴ�.

�̷��� dp�� ���� ����, �ð����⵵�� O(N^2)�� ���� �� �ִ�.
*/