#ifndef PRISON_BREAK_ALGO

#include <iostream>
#include <iomanip>
#include<string.h>


using namespace std;
int T, n, day, p, q, t;
int town[51][51]; // ���� ���� ����
int degree[51];   // �� ������ ����� ������ ����
double dp[51][101]; // j��° �� i�� ������ ���� Ȯ��

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int c = 0; c < T; c++)
	{
		cin >> n >> day >> p;
		memset(degree, 0, sizeof(degree));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> town[i][j];
				town[j][i] = town[i][j];
				if (town[i][j] == 1)
					degree[i]++;
			}
		}
		dp[p][0] = 1;
		for (int d = 1; d <= day; d++)
		{
			for (int i = 0; i < n; i++)
			{
				double& ret = dp[i][d];
				for (int j = 0; j < n; j++)
				{
					if (town[i][j] == 1)
						ret += dp[j][d - 1] / (double)degree[j];
				}
			}
		}
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			cin >> q;
			cout << setprecision(8) << dp[q][day] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

#endif // !PRISON_BREAK_ALGO

/*
1. ���� here �� ������ Ȯ����, ���� here �� ������ there �� ������ ��� Ȯ������ ���� ���̴�.

���� dp�� ���� ��ġ�� ���� Ȯ���� 1�̴�.
�׸��� �� ��¥�� � ��ġ�� ���� Ȯ����, �װſ� ������ ��ġ�� d-1 �Ͽ� ���� Ȯ���� ��� ���� ���̴�.

�̸� ���� ���� dp, �� �� ��ġ������ Ȯ���� ���ϰ�, �ű⿡�� t�� ��츦 �Ѵ�.
�׷��� �ð����⵵�� ���� �� �ִ�.

���� �װ� ���ؼ� Ʋ�ȳ�����.



*/