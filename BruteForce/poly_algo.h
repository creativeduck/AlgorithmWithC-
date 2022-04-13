#ifndef POLY_ALGO

#include <iostream>

const int MOD = 10000000;
using namespace std;
int T, n;
int polys[101][101]; // n, first 값 배열

int poly(int n, int first)
{
	if (n == first)
		return 1;
	int& total = polys[n][first];
	if (total != -1)
		return total;
	total = 0;
	for (int i = 1; i <= n - first; i++)
	{
		int add = first + i - 1;
		add *= poly(n - first, i);
		add %= MOD;
		total += add;
		total %= MOD;
	}
	return total;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int x = 0; x < 101; x++)
		{
			for (int y = 0; y < 101; y++)
				polys[x][y] = -1;
		}
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			ans += poly(n, j);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}

#endif // !POLY_ALGO

/*
폴리오미노는 각 행에서 연속된 사각형만 나올 수 있다.
따라서 첫 번째 사각형의 개수를 먼저 정하고,
두 번째 사각형의 개수가 정해지면 만들 수 있는 가지수를 구할 수 있다.
n개의 정사각형으로 만들 수 있는 폴리오미노는 첫번째 사각형의 개수가 1부터 n개일 때까지 poly(n-first)를 통해 구할 수 있고,
이때 두 번째 사각형의 길이에 따라 그 값을 곱해주면 총 개수가 나온다.
따라서 poly(n, first) = 시그마(poly(n-first, i) * (first + i - 1) 을 i가 1부터 n-first 까지로 하면 된다.

시간복잡도는, 총 n과 first의 가지수가 n^2개이고, poly 한 번 할 때마다 n번의 연산을 하므로,
총 O(n^3)의 시간복잡도를 갖는다.

다 베낀거긴 하지만 어느 정도 이해되는 거 같다.
*/