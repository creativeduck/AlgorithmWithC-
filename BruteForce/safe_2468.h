#ifndef SAFE_2468

#include <iostream>

using namespace std;
const int maxN = 100;
int land[maxN][maxN];
bool visited[maxN][maxN];
int N;
int safeZone = 1;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool inBound(int y, int x)
{
	if (y >= 0 && y < N && x >= 0 && x < N)
		return true;
	return false;
}

void makeClear()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
	}
}

int dfs(int y, int x, int height)
{
	if (land[y][x] <= height)
	{
		return 0;
	}
	int total = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (inBound(ny, nx) && !visited[ny][nx])
		{
			visited[ny][nx] = true;
			total += dfs(ny, nx, height);
		}
	}
	return total;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int low = maxN + 1, high = 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> land[i][j];
			if (land[i][j] < low)
				low = land[i][j];
			if (land[i][j] > high)
				high = land[i][j];
		}
	}
	for (int height = low; height < high; height++)
	{
		int area = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					visited[i][j] = true;
					int tmp = dfs(i, j, height);
					if (tmp >= 1)
						area++;
				}
			}
		}
		safeZone = max(safeZone, area);
		makeClear();
	}
	cout << safeZone;
	return 0;
}

#endif // !SAFE_2468

/*
���� ������ ���� ���� ���� ���� ���� ���Ѵ�.
�׸��� �� ���� ������ ���� ���鼭 ������ ���� ���� ��츦 ���Ѵ�.

dfs�� ����߰�, �� ���̺��� dfs�� ȣ���ϴ� �κ��� 3�� �ݺ��������� �ִ밡 100�̹Ƿ� �����ϰ� �ȴ�.


*/