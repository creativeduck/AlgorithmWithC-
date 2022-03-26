#ifndef OMOK_2615

#include <iostream>

using namespace std;
int board[19][19];
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
	// ��
	int right = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y, x + i) && board[y][x + i] == origin)
		{
			right++;
		}
		else
			break;
	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y, x-i) && board[y][x - i] == origin)
			right++;
		else
			break;
	}
	// �Ʒ�
	int bottom = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y+i, x) && board[y + i][x] == origin)
			bottom++;
		else
			break;
	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y - i, x) && board[y - i][x] == origin)
			bottom++;
		else
			break;
	}
	// �밢�� ���� �ϴ�
	int ret = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y + i, x + i) && board[y + i][x + i] == origin)
			ret++;
		else
			break;
	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y - i, x - i) && board[y - i][x - i] == origin)
			ret++;
		else
			break;
	}
	// �밢�� ���� ���
	int topRet = 1;
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y - i, x + i) && board[y - i][x + i] == origin)
			topRet++;
		else
			break;

	}
	for (int i = 1; i < 19; i++)
	{
		if (isBound(y + i, x - i) && board[y + i][x - i] == origin)
			topRet++;
		else
			break;
	}
	if (ret == 5 || bottom == 5 || right == 5 || topRet ==5)
	{
		if (topRet == 5)
		{
			row = y + 4;
			col = x - 4;
		}
		else
		{
			row = y;
			col = x;
		}
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
			if (board[i][j] != 0 && solve(i, j, board[i][j]))
			{
				ans = board[i][j];
				cout << ans << '\n';
				cout << row + 1 << " " << col + 1 << '\n';
				return;
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
�ϴ� ���������� ���� ���� ��� ������ ��������
�Ʒ�, ������, �밢�� ��, �밢�� �Ʒ��� �õ��ߴ�.
�ٵ� �ڵ尡 �� ��ǰ���� �� ����.

�ð����⵵�� ���� n^2�� �Լ��� ȣ���ؾ��ϴµ�,
�ش� �Լ������� n^2�� �ݺ� ����� �ϹǷ�,
���� n^4�̳�
*/