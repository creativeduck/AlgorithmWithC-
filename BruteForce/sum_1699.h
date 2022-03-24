#ifndef SUM_1699

#include <iostream>

using namespace std;
const int maxN = 100001;
int dp[maxN];
int n;

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j*j <= i; j++)
		{
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	cout << dp[n];
	return 0;
}
#endif // !SUM_1699

/*
���� ū �������� �� �ٸ�, �װ� �� ���� dp�� �̿��� �ּڰ��� ã�´�.

-- ���� --
ó������ ������ �߸� �־���.
���� ū �������� �� �͸��� ���� �ƴϾ���.
�׷��� �ݺ����� ���� �� ������ ���� ���� ���� �װ� �� ���� dp�� �̿��ؼ� �ּڰ��� ã�Ҵ�.

*/#ifndef SUM_1699

#include <iostream>

using namespace std;
const int maxN = 100001;
int dp[maxN];
int n;

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j*j <= i; j++)
		{
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	cout << dp[n];
	return 0;
}
#endif // !SUM_1699

/*
���� ū �������� �� �ٸ�, �װ� �� ���� dp�� �̿��� �ּڰ��� ã�´�.

-- ���� --
ó������ ������ �߸� �־���.
���� ū �������� �� �͸��� ���� �ƴϾ���.
�׷��� �ݺ����� ���� �� ������ ���� ���� ���� �װ� �� ���� dp�� �̿��ؼ� �ּڰ��� ã�Ҵ�.

*/