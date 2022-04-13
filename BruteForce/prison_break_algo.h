#ifndef PRISON_BREAK_ALGO

#include <iostream>
#include <iomanip>
#include<string.h>


using namespace std;
int T, n, day, p, q, t;
int town[51][51]; // 마을 연결 여부
int degree[51];   // 각 마을에 연결된 간선의 개수
double dp[51][101]; // j번째 날 i번 마을에 있을 확률

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
1. 오늘 here 에 도착할 확률은, 어제 here 과 근접한 there 에 도착할 모든 확률들을 더한 것이다.

먼저 dp로 현재 위치에 있을 확률은 1이다.
그리고 각 날짜에 어떤 위치에 있을 확률은, 그거와 인접한 위치에 d-1 일에 있을 확률을 모두 더한 것이다.

이를 통해 먼저 dp, 즉 각 위치에서의 확률을 구하고, 거기에다 t의 경우를 한다.
그래야 시간복잡도를 줄일 수 있다.

내가 그걸 못해서 틀렸나보다.



*/