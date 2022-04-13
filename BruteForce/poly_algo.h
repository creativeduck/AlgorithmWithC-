#ifndef POLY_ALGO

#include <iostream>

const int MOD = 10000000;
using namespace std;
int T, n;
int polys[101][101]; // n, first �� �迭

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
�������̳�� �� �࿡�� ���ӵ� �簢���� ���� �� �ִ�.
���� ù ��° �簢���� ������ ���� ���ϰ�,
�� ��° �簢���� ������ �������� ���� �� �ִ� �������� ���� �� �ִ�.
n���� ���簢������ ���� �� �ִ� �������̳�� ù��° �簢���� ������ 1���� n���� ������ poly(n-first)�� ���� ���� �� �ְ�,
�̶� �� ��° �簢���� ���̿� ���� �� ���� �����ָ� �� ������ ���´�.
���� poly(n, first) = �ñ׸�(poly(n-first, i) * (first + i - 1) �� i�� 1���� n-first ������ �ϸ� �ȴ�.

�ð����⵵��, �� n�� first�� �������� n^2���̰�, poly �� �� �� ������ n���� ������ �ϹǷ�,
�� O(n^3)�� �ð����⵵�� ���´�.

�� �����ű� ������ ��� ���� ���صǴ� �� ����.
*/