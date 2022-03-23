#ifndef MAKE_ONE_1463

#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int maxN = 1000001;
int dp[maxN];
int N;

int minVal(int a, int b, int c)
{
	a = min(a, b);
	return min(a, c);
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < maxN; i++) dp[i] = maxN;
	dp[1] = 0;
	int trd = maxN, sec = maxN, one = maxN;
	for (int i = 2; i <= N; i++)
	{
		int trd = maxN, sec = maxN, one = maxN;
		if (i%3==0)
			trd = dp[i / 3] + 1;
		if (i%2 ==0)
			sec = dp[i / 2] + 1;
		one = dp[i - 1] + 1;
		int tmp = minVal(one, sec, trd);
		dp[i] = tmp;
	}
	cout << dp[N];
	return 0;
}

#endif // !MAKE_ONE_1463