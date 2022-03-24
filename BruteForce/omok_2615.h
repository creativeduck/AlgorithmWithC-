#ifndef OMOK_2615

#include <iostream>

using namespace std;
int board[19][19];
bool visited[19][19];
int row = 0;
int col = 0;

bool isBound(int y, int x)
{
	if (y >= 0 && y < 19 && x >= 0 && x < 19)
		return true;
	return false;
}

bool solve(int y, int x, int origin)
{
	if (!isBound(y, x))
		return false;
	// 우

	int right = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y, x + i) && board[y][x + i] == origin)
		{
			right++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y, x-i) && board[y][x - i] == origin)

		{
			right++;
		}
		else
		{
			break;
		}
	}
	// 아래
	int bottom = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y+i, x) && board[y + i][x] == origin)
		{
			bottom++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y - i, x) && board[y - i][x] == origin)
		{
			bottom++;
		}
		else
		{
			break;
		}
	}
	// 대각선 우측 하단
	int ret = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y + i, x + i) && board[y + i][x + i] == origin)
		{
			ret++;
		}
		else
		{
			break;
		}

	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y - i, x - i) && board[y - i][x - i] == origin)
		{
			ret++;
		}
		else
		{
			break;
		}
	}
	// 대각선 우측 상단
	int topRet = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y - i, x + i) && board[y - i][x + i] == origin)
		{
			topRet++;
		}
		else
		{
			break;
		}

	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y + i, x - i) && board[y + i][x - i] == origin)
		{
			topRet++;
		}
		else
		{
			break;
		}
	}
	if (ret == 5 || bottom == 5 || right == 5)
	{
		row = y;
		col = x;
		return true;
	}
	else if (topRet == 5)
	{
		row = y+4;
		col = x-4;
		return true;
	}
	return false;
}

void init()
{
	int ans = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			int num = 0;
			if (board[i][j] != 0)
			{
				num = board[i][j];
				bool great = solve(i, j, num);
				if (great)
				{
					ans = num;
					cout << ans << '\n';
					cout << row+1 << " " << col+1 << '\n';
					return;
				}
			}
		}
	}
	cout << 0 << '\n';
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];
	}
	init();
	return 0;
}
#endif // !OMOK_2615

/*


*/