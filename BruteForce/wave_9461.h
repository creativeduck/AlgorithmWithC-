#ifndef WAVE_9461

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
		dp[i] = dp[i - 1] + dp[i - 5];
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

#endif // !WAVE_9461

/*
수열의 규칙을 찾아서 반복문을 통해 구했다.
시간복잡도는 입력받는 것 제외하고 O(n)이 되도록 했다.
*/