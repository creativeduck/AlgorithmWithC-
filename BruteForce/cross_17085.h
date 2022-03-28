#ifndef CROSS_17085

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
const int maxN = 15;
int N, M;
int board[maxN][maxN];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ans = 1;
int c[maxN][maxN];
bool visited[maxN][maxN];


int square(int n)
{
	return 4 * (n-1) + 1;
}

bool isBound(int y, int x)
{
	if (y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}

int solve(int y, int x, int cnt)
{
	if (!isBound(y, x) || board[y][x] == 0 || visited[y][x])
		return cnt;
	for (int i = 1; i < 15; i++)
	{
		int k = 0;
		for (k; k < 4; k++)
		{
			int ny = y + i * dy[k];
			int nx = x + i * dx[k];
			if (!isBound(ny, nx) || board[ny][nx] == 0)
			{
				i = 16;
				break;
			}
		}
		if (k == 4)
		{
			cnt++;
		}
	}
	return cnt;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	char tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			if (tmp == '#')
				board[i][j] = 1;
		}
	}
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1)
			{
				bool flag = true;
				int cross = solve(i, j, 1); // 십자가가 있다면, 이때 길이를 반환한다.
				c[i][j] = cross;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cout << c[i][j];
			if (c[i][j] > 1)
			{
				int gijun =-1;
				for (int mine = c[i][j]; mine > 0; mine--)
				{
					gijun++;
					cout << endl;
					cout << " mine " << mine << " / " << gijun << endl;
					cout << endl;

					for (int k = i; k < N; k++)
					{
						for (int z = j + 1; z < M; z++)
						{
							int tmpCross = solve(k, z, 1);
							cout << "tmp " << tmpCross << " k " << k << " z " << z << endl;
							
						}
					}

					//for (int k = i; k < N; k++)
					//{
					//	for (int z = j + 1; z < M; z++)
					//	{
					//		if (c[k][z] > 0)
					//		{
					//			cout << " k " << k << " z " << z << endl;
					//			for (int pine = c[k][z]; pine > 0; pine--)
					//			{
					//				cout << " pine " << pine << (z - pine <= j) << "asdf" << z << endl;
					//				if ((k - (pine-1) <= i && i <= k + (pine - 1)) && (j - (mine - 1) <= z && z <= j + (mine - 1)))
					//				{
					//					cout << "wow" << endl;
					//					continue;
					//				}
					//				if ((i <= k && k <= i + (mine-1)) && (z - (pine - 1) <= j && j <= z))
					//				{
					//					cout << "wow 2" << endl;
					//					continue;
					//				}
					//				int sq1 = square(mine);
					//				int sq2 = square(pine);
					//				cout << sq1 << " / " << sq2 << " pine " << pine << " mi ne " << mine << endl;
					//				ans = max(ans, sq1 * sq2);
					//				cout << ans << " ytto " << i << " / " << j << " / " << k << " / " << z << endl;
					//			}
					//		}
					//	}
					//}
				}
			}

		}
	}
	// 중복 십자가 있는지 확인


	cout << ans;
	return 0;
}

#endif // !CROSS_17085

/*
아예 접근을 못 했다.
그냥 다른 사람 정답을 보고 풀었다.
최대한 얻어가고, 
대신.... 돌리진 말자.
북마크한 다음에, 나중에 다시 풀 때 돌리자


*/