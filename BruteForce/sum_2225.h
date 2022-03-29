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
사실 답을 보고 풀었다.
완전탐색으로 접근하고 DP를 적용하려고 했지만, 끝내 적용할 방법을 찾지 못했다.

이건 K개로 N을 만드는 경우의 수를 담은 2차원 배열을 사용해 푸는 방법이 있었다.
K개를 사용해 N을 만드는 dp에서,
이건 K-1개를 사용해 N-L을 만드는 경우의 수를 모두 더한 것과 같다.
이때 L은 0부터 N까지 다 된다.
거기다 L만 더해주면 K, N 이 되니까.

이걸 O(n^2)로 바꾸는 방법도 있다.
결국 dp[k][n]은 k개의 정수로 n-1을 만드는 방법에 1을 더한 것과,
k-1개의 정수로 n을 만드는 방법에 0을 더한 것과 같다.
그래서 그걸 사용해 j, k 가 사용되는 반복문을 아예 하나로 만들어줄 수 있다.
dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000000;


*/