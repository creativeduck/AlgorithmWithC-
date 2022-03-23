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
�ϴ� ��������� �ذ��ߴ�.

�׸��� �� ���ں� �ִ��� ���ϴ� ���̱� ������,
������ ������ ��� ���� ���� ���� ���� ���̰� ���� ���.
�׷��Ƿ�, dp�� ����� �� �ε��� �� ���̸� �����ϰ�,
���� �ش� �ε����� ���� �ʿ��ϸ� �ٷ� dp�� ��ȯ�ϵ��� �ߴ�.

*/