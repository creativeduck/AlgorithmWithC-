#ifndef TMP

#include <iostream>

using namespace std;
const int maxN = 1001;
int N;
int nums[maxN];
int dp[maxN];

int solve(int start)
{
	int& cnt = dp[start];
	if (cnt != -1)
	{
		return cnt;
	}
	cnt = 1;
	for (int i = start+1; i < N; i++)
	{
		if (nums[i] > nums[start])
		{
			cnt = max(cnt, solve(i)+1);
		}
	}
	dp[start] = cnt;
	return cnt;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < maxN; i++) dp[i] = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		tmp = max(tmp, solve(i));
	}
	cout << tmp << endl;

	return 0;
}

#endif // !TMP

/*
일단 재귀적으로 해결했다.

그리고 각 숫자별 최댓값을 구하는 것이기 때문에,
동일한 숫자의 경우 가장 먼저 나온 것이 길이가 가장 길다.
그러므로, dp를 사용해 각 인덱스 별 길이를 저장하고,
이후 해당 인덱스의 값이 필요하면 바로 dp로 반환하도록 했다.

*/