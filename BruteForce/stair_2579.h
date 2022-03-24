#ifndef STAIR_2579

#include <iostream>

using namespace std;
const int maxN = 301;
int sums[maxN];
int dp[maxN];
int n;

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> sums[i];
	dp[0] = sums[0]; dp[1] = sums[0] + sums[1]; dp[2] = max(sums[0] + sums[2], sums[1] + sums[2]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(sums[i] + dp[i - 2], sums[i] + sums[i - 1] + dp[i-3]);
	}
	cout << dp[n-1];
	return 0;
}

#endif // !STAIR_2579

/*
세 번 연속으로 값을 갖지 못하므로,
ooxo, oxoo 으로 최댓값을 구해서 dp를 사용해서 풀었다.

-- 오답 --
처음에 조건은 잘 찾았다고 생각했는데,
n-3번째 값도 더해주어야 이전 값들을 고려할 수 있다는 걸 뒤늦게 알았다.

*/