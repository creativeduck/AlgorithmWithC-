#ifndef STAIR_9095

#include <iostream>

using namespace std;
const int maxN = 101;
const int maxLeft = 1000000000;
int n;
int dp[maxN][maxN];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}


	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j < 1)
				dp[i][j] = (dp[i - 1][j + 1]) % maxLeft;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % maxLeft;
		}
	}
	int ans = 0;
	for (int j = 0; j <= 9; j++)
	{
		ans = (ans + dp[n][j]) % maxLeft;
	}
	cout << ans;
	return 0;
}

#endif // !STAIR_9095