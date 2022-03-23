#ifndef SUM_9095

#include <iostream>

using namespace std;

int n;
int dp[1001];
int T;


int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		cout << dp[n] << '\n';
	}


	return 0;
}

#endif // !SUM_9095