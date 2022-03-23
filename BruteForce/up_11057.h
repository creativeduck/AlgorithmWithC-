#ifndef UP_11057

#include <iostream>

using namespace std;
const int maxN = 1001;
const int maxLeft = 10007;
int N;
int dp[maxN][10];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % maxLeft;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = (ans + dp[N][i]) % maxLeft;
	}
	cout << ans;

	return 0;
}

#endif // !UP_11057