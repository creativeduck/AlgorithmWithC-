#ifndef BI_2193

#include <iostream>

using namespace std;
const int maxN = 91;

int N;
long long dp[maxN][2];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	dp[1][0] = 0; dp[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] += dp[i - 1][0];
	}
	cout << dp[N][0] + dp[N][1];



	return 0;
}

#endif // !BI_2193