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
가장 큰 제곱수를 뺀 다면, 그걸 뺀 것의 dp를 이용해 최솟값을 찾는다.

-- 오답 --
처음에는 조건을 잘못 주었다.
가장 큰 제곱수를 뺀 것만이 답은 아니었다.
그래서 반복문을 통해 각 제곱수 별로 빼준 다음 그걸 뺀 것의 dp를 이용해서 최솟값을 찾았다.

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
가장 큰 제곱수를 뺀 다면, 그걸 뺀 것의 dp를 이용해 최솟값을 찾는다.

-- 오답 --
처음에는 조건을 잘못 주었다.
가장 큰 제곱수를 뺀 것만이 답은 아니었다.
그래서 반복문을 통해 각 제곱수 별로 빼준 다음 그걸 뺀 것의 dp를 이용해서 최솟값을 찾았다.

*/