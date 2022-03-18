#ifndef PRIME_SUM_1644

#include <iostream>
#include <vector>
using namespace std;

int N;
const int maxN = 4000001;

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	// 소수 배열 만들기
	vector<int> primes;
	vector<bool> isPrimes(maxN, true);
	isPrimes[1] = false;
	for (int i = 2; i * i < maxN; i++)
	{
		if (!isPrimes[i]) continue;
		for (int j = i * i; j <= N; j += i)
		{
			isPrimes[j] = false;
		}
	}

	for (int i = 2; i < maxN; i++)
	{
		if (isPrimes[i]) primes.push_back(i);
	}
	int len = primes.size();
	int start = 0, end = 0, sum = 0, ans = 0;
	for (start; start < len; start++)
	{
		while (sum < N && end < len)
		{
			sum += primes[end];
			end++;
		}
		if (end == len) break;
		if (sum == N) ans++;
		sum -= primes[start];
	}
	cout << ans;
	return 0;
}

#endif // !PRIME_SUM_1644