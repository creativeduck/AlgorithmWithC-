#ifndef TMP

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

#endif // !TMP

/*


*/