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
일단 재귀적으로 해결했다.

그리고 각 숫자별 최댓값을 구하는 것이기 때문에,
동일한 숫자의 경우 가장 먼저 나온 것이 길이가 가장 길다.
그러므로, dp를 사용해 각 인덱스 별 길이를 저장하고,
이후 해당 인덱스의 값이 필요하면 바로 dp로 반환하도록 했다.

*/