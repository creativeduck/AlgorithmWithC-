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
�� �� �������� ���� ���� ���ϹǷ�,
ooxo, oxoo ���� �ִ��� ���ؼ� dp�� ����ؼ� Ǯ����.

-- ���� --
ó���� ������ �� ã�Ҵٰ� �����ߴµ�,
n-3��° ���� �����־�� ���� ������ ����� �� �ִٴ� �� �ڴʰ� �˾Ҵ�.

*/