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
�ʱ⿣ ���� ���� �丶����� ��ǥ�� �߰��Ѵ�.
�� ���ึ�� ���� �丶�� ���� �� ���� �丶�並 �Ͱ� �� ��, �� �丶����� ��ǥ�� �߰��Ѵ�.
�̷��� �ݺ������� ���� �ּ� Ƚ���� ���Ѵ�.

�̶� ó������ �׳� �ݺ������� �˻��ϰ�, �׷��� �ð��ʰ��� ����.

�׷��� ������ �;�� �ϴ� �丶�� ������ ���� ���ϰ�,
�� ���� �Ǹ� return �ϵ��� �ߴ�.
�׸��� ������ �� ���� �ʾҴµ� ������ ������ ���� ���ϴ� ����̹Ƿ�, while ���� ������ -1�� ��ȯ�ϵ��� �ߴ�.
*/