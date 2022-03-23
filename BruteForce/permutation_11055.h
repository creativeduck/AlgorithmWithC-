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
�ϴ� ���ȣ�⿡�ٰ� dp�� �����ϴ� ������� ������ Ǯ����.
n���� �ݺ�����, �� ��� ȣ�⿡ n���� �ݺ�����, �� ��� ȣ���� n�� �Ѵٰ� �ϸ�
n �������� ������ �� ����.

�ٸ� ��ĵ� �־ �װ� �����ߴ�.

�ݺ����� ���鼭 �� �ε������� �˻縦 �ϴµ�,
�̶� �ش� �ε������� ���� �ε������� ���� ���� �ִٸ�,
�� �ε��� ���� ���� ���� ���� �Ͱ� �׳� ���� �� �� �ִ��� ���� �ߴ�.
�̷��� �ؼ� dp�� �ִ񰪵��� �����ߴ�.


*/