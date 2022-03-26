#ifndef TMP

#include <iostream>

using namespace std;
const int maxN = 101;
long long dp[maxN];
int T, N;

long long solve(int n)
{
	if (dp[n] != -1)
		return dp[n];
	for (int i = 5; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	return dp[n];
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < maxN; i++) dp[i] = -1;
	dp[0] = 0; dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << solve(N) << '\n';
	}

	return 0;
}

#endif // !TMP

/*
�ϴ� ��������� �ذ��ߴ�.

�׸��� �� ���ں� �ִ��� ���ϴ� ���̱� ������,
������ ������ ��� ���� ���� ���� ���� ���̰� ���� ���.
�׷��Ƿ�, dp�� ����� �� �ε��� �� ���̸� �����ϰ�,
���� �ش� �ε����� ���� �ʿ��ϸ� �ٷ� dp�� ��ȯ�ϵ��� �ߴ�.

*/