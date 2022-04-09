#ifndef SAFE_2468

#include <iostream>
#include <queue>

using namespace std;
const int maxN = 1000;
int board[maxN][maxN];
int M, N;
int days = 0;
queue<pair<int, int>> tomatos;
int cnt = 0;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool inBound(int y, int x)
{
	if (y >= 0 && y < N && x >= 0 && x < M)
		return true;
	return false;
}
int bfs(int total)
{
	while (tomatos.size() > 0)
	{
		if (cnt == total)
			return days;
		int size = tomatos.size();
		days++;
		for (int i = 0; i < size; i++)
		{
			pair<int, int> p = tomatos.front();
			tomatos.pop();
			int y = p.first;
			int x = p.second;
			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (inBound(ny, nx) && board[ny][nx] == 0)
				{
					board[ny][nx] = 1;
					pair<int, int> tmpP = make_pair(ny, nx);
					tomatos.push(tmpP);
					cnt++;

				}
			}
		}
	}
	return -1;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	int total = M * N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				pair<int, int> p = make_pair(i, j);
				tomatos.push(p);
				cnt++;
			}
			if (board[i][j] == -1)
				total--;
		}
	}
	cout << bfs(total);
	return 0;
}

#endif // !SAFE_2468

/*
초기엔 현재 익은 토마토들의 좌표를 추가한다.
각 시행마다 익은 토마토 인접 안 익은 토마토를 익게 한 후, 그 토마토들의 좌표를 추가한다.
이러한 반복시행을 통해 최소 횟수를 구한다.

이때 처음에는 그냥 반복문으로 검사하고, 그래서 시간초과가 났다.

그래서 지금은 익어야 하는 토마토 개수를 먼저 구하고,
그 값이 되면 return 하도록 했다.
그리고 어차피 다 익지 않았는데 시행이 끝나면 익지 못하는 경우이므로, while 문이 끝나면 -1을 반환하도록 했다.
*/