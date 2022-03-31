#ifndef BITONIC_11054

#include <iostream>

using namespace std;
const int maxN = 1001;
int N;
int nums[maxN];
int dpUp[maxN];
int dpDown[maxN];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> nums[i];
	for (int i = 1; i <= N; i++)
	{
		dpUp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (nums[j] < nums[i] && dpUp[i] < dpUp[j] + 1)
			{
				dpUp[i] = dpUp[j] + 1;
			}
		}
	}
	for (int i = N; i > 0; i--)
	{
		dpDown[i] = 1;
		for (int j = N; j >= i; j--)
		{
			if (nums[j] < nums[i] && dpDown[i] < dpDown[j] + 1)
				dpDown[i] = dpDown[j] + 1;
		}
	}
	int maxVal = 0;
	for (int i = 0; i < N; i++)
	{
		maxVal = max(maxVal, dpUp[i] + dpDown[i] - 1);
	}
	cout << maxVal;
	return 0;
}

#endif // !BITONIC_11054

/*
어떤 수에 대해서 그걸 기준으로, 앞에는 오름차순과 뒤에는 내림차순이 있어야 한다.
그럼 어떤 수를 기준으로 그 앞엔 오름차순이닞, 그 뒤는 내림차순인지 판별해야 한다.

일단 부르트포스를 통해서 문제를 해결했고,
dp를 적용해서 시간초과를 방지해야 한다.
그런데 틀린 로직이 있었고,


*/