#ifndef SUM_1806

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 100001;
int N, S;
int arr[maxN] = { 0, };

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0, end = 0, sum = 0, len = maxN, tmp = 0;
	for (start; start < N; start++)
	{
		while (sum < S && end < N)
		{
			sum += arr[end];
			end++;
		}
		if (sum == S)
		{
			tmp = end - start;
			if (tmp < len)
				len = tmp;
		}
		sum -= arr[start];
	}
	if (len == maxN)
		len = 0;
	cout << len;
	return 0;
}

#endif // !SUM_1806