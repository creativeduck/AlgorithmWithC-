#ifndef CROSS_17085

#include <iostream>

using namespace std;
const int maxN = 15;
int N, M;
char board[maxN][maxN];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ans = 1;

bool isBound(int y, int x)
{
	if (y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

int find(int y, int x)
{
	int len = 0;
	for (int i = 1; i < 15; i++)
	{
		bool flag = true;
		for (int k = 0; k < 4; k++)
		{
			int ny = y + i * dy[k];
			int nx = x + i * dx[k];
			if (!(isBound(ny, nx) && board[ny][nx] == '#'))
				flag = false;
		}
		if (flag)
			len = i;
		else
			break;
	}
	return len;
}

void makeCross(int y, int x, int len, char c)
{
	for (int i = 0; i <= len; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			int ny = y + i * dy[k];
			int nx = x + i * dx[k];
			board[ny][nx] = c;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	// 십자가 찾기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == '#')
			{
				int len = find(i, j);
				if (len > 0)
				{
					// 첫번째 십자가 1부터 최대 크기까지
					for (int z = 1; z <= len; z++)
					{
						ans = max(ans, (z * 4 + 1));
						makeCross(i, j, z, '*');

						for (int r = 0; r < N; r++)
						{
							for (int c = 0; c < M; c++)
							{
								if (board[r][c] == '#')
								{
									int secLen = find(r, c);
									if (secLen > 0)
										ans = max(ans, (secLen * 4 + 1) * (z * 4 + 1));
								}
							}
						}
						makeCross(i, j, z, '#');
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

#endif // !CROSS_17085

/*
1. 십자가 찾기
2. 하나의 십자가에 대해, 중복되지 않는 십자가 찾기
2-1. 이때, 그 하나의 십자가의 크기를 줄이면서도 중복되지 않는 십자가 찾기
3. 곱의 최댓값 구하기

일단 이렇게 엄청난 부르트포스로 구하긴 했다.
단, 시간초과가 날 것 같다. 엄청나게 for 문을 반복했기 때문이다.
무려 5중 for 문이다.

-- 답 참고함 -- 
단, 그래도 내 로직을 좀 사용하면서 수정했다.
이젠 어떻게 돌아가는지 이해는 좀 간다.

*/