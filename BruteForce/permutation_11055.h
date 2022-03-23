#ifndef PERMUTATION_11055

#include <iostream>

using namespace std;
const int maxN = 1001;
int N;
int nums[maxN];
int dp[maxN];

int solve(int start)
{
	int tmp = dp[start];
	if (tmp != -1)
		return tmp;
	tmp = nums[start];
	for (int i = start+1; i < N; i++)
	{
		if (nums[i] > nums[start])
			tmp = max(tmp, solve(i) + nums[start]);
	}
	dp[start] = tmp;
	return tmp;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i];
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = nums[i];
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = max(dp[i], dp[j] + nums[i]);
			}
		}
		if (tmp < dp[i])
			tmp = dp[i];
	}
	cout << tmp;
	return 0;
}

#endif // !PERMUTATION_11055

/*
일단 재귀호출에다가 dp를 적용하는 방식으로 문제를 풀었다.
n번의 반복문에, 각 재귀 호출에 n번의 반복문에, 각 재귀 호출을 n번 한다고 하면
n 세제곱이 나오는 것 같다.

다른 방식도 있어서 그걸 적용했다.

반복문을 돌면서 각 인덱스별로 검사를 하는데,
이때 해당 인덱스보다 작은 인덱스들중 작은 값이 있다면,
그 인덱스 값에 현재 값을 더한 것과 그냥 현재 값 중 최댓값을 고르게 했다.
이렇게 해서 dp에 최댓값들을 저장했다.


*/