#ifndef CARD_11052

#include <iostream>

using namespace std;
const int maxN = 1001;
int N;
int P[maxN];
int dp[maxN];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> P[i];
	dp[1] = P[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i] = P[i];
		for (int j = 1; 2*j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
	}
	cout << dp[N];
	return 0;
}

#endif // !CARD_11052

/*
이전 dp와 dp[1]을 더한 값과, 해당 dp값 중 최댓값을 계속 dp에 저장하면서
최댓값을 구하는 로직을 사용했다.

어쩌면 당연하지만 이렇게 단순하게는 안 되었고,
반복문을 통해 i/2까지 경우를 주어서 최댓값을 구하도록 했다.

*/