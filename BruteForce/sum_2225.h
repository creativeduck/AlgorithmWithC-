#ifndef SUM_2225

#include <iostream>

using namespace std;
const int maxN = 1000000000;
const int maxL = 201;
int N, K;
int dp[maxL][maxL];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i <= N; i++) dp[1][i] = 1;
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= maxN;
			}
		}
	}
	cout << dp[K][N];
	return 0;
}

#endif // !SUM_2225

/*
��� ���� ���� Ǯ����.
����Ž������ �����ϰ� DP�� �����Ϸ��� ������, ���� ������ ����� ã�� ���ߴ�.

�̰� K���� N�� ����� ����� ���� ���� 2���� �迭�� ����� Ǫ�� ����� �־���.
K���� ����� N�� ����� dp����,
�̰� K-1���� ����� N-L�� ����� ����� ���� ��� ���� �Ͱ� ����.
�̶� L�� 0���� N���� �� �ȴ�.
�ű�� L�� �����ָ� K, N �� �Ǵϱ�.

�̰� O(n^2)�� �ٲٴ� ����� �ִ�.
�ᱹ dp[k][n]�� k���� ������ n-1�� ����� ����� 1�� ���� �Ͱ�,
k-1���� ������ n�� ����� ����� 0�� ���� �Ͱ� ����.
�׷��� �װ� ����� j, k �� ���Ǵ� �ݺ����� �ƿ� �ϳ��� ������� �� �ִ�.
dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000000;


*/