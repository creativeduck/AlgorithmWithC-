#ifndef SUM_2003

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M, cnt = 0;;

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int nums[10010] = {0,};
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		nums[i] = num;
	}
	int start = 0, end = 0, ans = 0;
	int flag = false;
	for (start; start < N; start++)
	{
		// 함 구하기
		while (ans < M && end < N)
		{
			ans += nums[end];
			end++;
		}
		if (ans == M) cnt++;
		ans -= nums[start];

	}
	cout << cnt;
	return 0;
}

#endif // !SUM_2003