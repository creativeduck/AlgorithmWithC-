#ifndef SUM_9095

#include <iostream>

using namespace std;
int T, n;
int dp[12];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << '\n';
	}
	return 0;
}

#endif // !SUM_9095

/*
3보다 큰 수들은 모두 세 경우로 나뉜다.
3 더하기 그 이전 조합들
2 더하기 그 이전 조합들
1 더하기 그 이전 조합들
그래서 4부터 더해준 것이다.
*/