#ifndef PAPER_1780

#include <iostream>

using namespace std;
int N, len, zero = 0, oneP = 0, oneN = 0;
const int maxN = 2188;
bool visited[maxN][maxN];
int papers[maxN][maxN];

void getCnt(int x, int y, int len)
{
	if (visited[y][x])
		return;
	int start = papers[y][x];
	for (int i = y; i < y + len; i++)
	{
		for (int j = x; j < x + len; j++)
		{
			if (start != papers[i][j])
			{
				for (int k = 0; k < 3; k++)
				{
					for (int z = 0; z < 3; z++)
					{
						int newLen = len / 3;
						getCnt(x + newLen * z, y + newLen * k, newLen);
					}
				}
				return;
			}
		}
	}
	if (start == 0)
		zero++;
	else if (start == 1)
		oneP++;
	else
		oneN++;
	visited[y][x] = true;
}


int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> papers[i][j];
		}
	}
	getCnt(0, 0, N);
	cout << oneN << '\n' << zero << '\n' << oneP;
	return 0;
}

#endif // !PAPER_1780