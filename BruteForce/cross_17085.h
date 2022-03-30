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
	// ���ڰ� ã��
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == '#')
			{
				int len = find(i, j);
				if (len > 0)
				{
					// ù��° ���ڰ� 1���� �ִ� ũ�����
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
1. ���ڰ� ã��
2. �ϳ��� ���ڰ��� ����, �ߺ����� �ʴ� ���ڰ� ã��
2-1. �̶�, �� �ϳ��� ���ڰ��� ũ�⸦ ���̸鼭�� �ߺ����� �ʴ� ���ڰ� ã��
3. ���� �ִ� ���ϱ�

�ϴ� �̷��� ��û�� �θ�Ʈ������ ���ϱ� �ߴ�.
��, �ð��ʰ��� �� �� ����. ��û���� for ���� �ݺ��߱� �����̴�.
���� 5�� for ���̴�.

-- �� ������ -- 
��, �׷��� �� ������ �� ����ϸ鼭 �����ߴ�.
���� ��� ���ư����� ���ش� �� ����.

*/