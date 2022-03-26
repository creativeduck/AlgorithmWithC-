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
���� dp�� dp[1]�� ���� ����, �ش� dp�� �� �ִ��� ��� dp�� �����ϸ鼭
�ִ��� ���ϴ� ������ ����ߴ�.

��¼�� �翬������ �̷��� �ܼ��ϰԴ� �� �Ǿ���,
�ݺ����� ���� i/2���� ��츦 �־ �ִ��� ���ϵ��� �ߴ�.

*/