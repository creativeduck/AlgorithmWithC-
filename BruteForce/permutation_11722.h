#ifndef PERMUTATION_11722

#include <iostream>

using namespace std;
const int maxN = 1001;
int sums[maxN];
int dp[maxN];
int N;

int solve(int start)
{
	if (dp[start] != -1)
		return dp[start];
	int tmp = 1;
	for (int i = start + 1; i < N; i++)
	{
		if (sums[i] < sums[start])
		{
			tmp = max(tmp, solve(i) + 1);
		}
	}
	dp[start] = tmp;
	return tmp;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> sums[i];
	for (int i = 0; i < maxN; i++) dp[i] = -1;
	int tmp = 1;
	for (int i = 0; i < N; i++)
	{
		tmp = max(tmp, solve(i));
	}
	cout << tmp;
	return 0;
}

#endif // !PERMUTATION_11722

/*



*/