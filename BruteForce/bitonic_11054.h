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
� ���� ���ؼ� �װ� ��������, �տ��� ���������� �ڿ��� ���������� �־�� �Ѵ�.
�׷� � ���� �������� �� �տ� ���������̈�, �� �ڴ� ������������ �Ǻ��ؾ� �Ѵ�.

�ϴ� �θ�Ʈ������ ���ؼ� ������ �ذ��߰�,
dp�� �����ؼ� �ð��ʰ��� �����ؾ� �Ѵ�.
�׷��� Ʋ�� ������ �־���,


*/