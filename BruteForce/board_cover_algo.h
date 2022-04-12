#ifndef BOARD_COVER_ALGO

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int H, W, R, C;
vector<string> board;
vector<vector<pair<int, int>>> rotations;
int covered[10][10];
int blockSize;
int best;

// ��� ���� �� ��ȯ�ϴ� �Լ�
vector<string> rotate(const vector<string>& block)
{
	// block ������ ũ�⸸ŭ, �׸��� �� ���ڿ��� block ������ ���ڿ��� ũ�⸸ŭ
	vector<string> rot(block[0].size(), string(block.size(), ' '));
	for (int i = 0; i < block.size(); i++)
	{
		for (int j = 0; j < block[0].size(); j++)
			rot[j][block.size() - i - 1] = block[i][j];
	}
	return rot;
}

// �� �����̼��� ��� ����� �Լ� - �� �����̼ǿ��� ����� �ϴ�, �� '.'�� ���� �����ǥ�� �� �־���
void generateRotations(vector<string>& block)
{
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++)
	{
		int originY = -1, originX = -1; // �� �� ���� ��ǥ�� ���������� ����
		for (int i = 0; i < block.size(); i++)
		{
			for (int j = 0; j < block[i].size(); j++)
			{
				if (block[i][j] == '#')
				{
					if (originY == -1)
					{
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		// 90�� ȸ��
		block = rotate(block);
	}
	// �ߺ��� �� ������ �������ֱ�
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size(); 	
}


// ���忡 ��� ���� ���� �Լ�
bool set(int y, int x, const vector<pair<int, int>>& rotation, int delta)
{
	bool ret = true;
	for (int i = 0; i < rotation.size(); i++)
	{
		int ny = y + rotation[i].first;
		int nx = x + rotation[i].second;
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) // ��ǥ ���� ����� �� ��
			ret = false;
		// �ϴ� ����� ���µ�, ������ ���� ���� 1���� Ŀ���� �� ��
		else if ((covered[ny][nx] += delta) > 1)
			ret = false;
	}
	// �� �������ٸ�, true ��ȯ
	return ret;
}
// ����ġ��
bool pruning(int placed)
{
	int emptys = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (covered[i][j] == 0)
				emptys++;
		}
	}
	if (emptys / blockSize + placed <= best)
		return true;
	return false;
}

// ���� ��� ���� ������ �Ű������� ����
void search(int placed)
{
	if (pruning(placed))
		return;
	int y = -1, x = -1;
	// ���� �� �ִ� �� �� ���� ��ǥ ã��
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (covered[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}

	// ���� ���� ���ٸ�, ��ȯ
	if (y == -1)
	{
		best = max(best, placed);
		return;
	}

	for (int rot = 0; rot < rotations.size(); rot++)
	{
		// ���� ���� Ž���ϱ�
		if (set(y, x, rotations[rot], 1))
			search(placed + 1);
		// �ٽ� ���ֱ�
		set(y, x, rotations[rot], -1);
	}

	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}


int solve()
{
	best = 0;
	// �̹� ������ ���� 1�� ǥ��
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}
	search(0);
	return best;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> H >> W >> R >> C;
		board.clear();
		vector<string> block;
		string tmpS;
		for (int i = 0; i < H; i++)
		{
			cin >> tmpS;
			board.push_back(tmpS);
		}
		for (int i = 0; i < R; i++)
		{
			cin >> tmpS;
			block.push_back(tmpS);
		}
		generateRotations(block);
		cout << solve() << '\n';
	}
	return 0;
}

#endif // !BOARD_COVER_ALGO

/*
1. �� ��� ȸ���� �͵�(�� 4��) �迭 �����
2. �� ���� ���ʺ��� �����ؼ� ��� ä���
3. ����ȭ�ϱ�
���� ���� �� ����/���ũ�� + ���� ���ũ�� <= ������ ���, ����ġ��

�ᱹ ������ �ߴ�.
�迭�� ũ�⵵ ���� �������� �ִ� �͵� ������ �߿��ϴ�.


set���� n������ �����ϸ�, ���� search ���� ������ �� �ص� �ȴ�.
��, set���� �� Ƚ���� ����ؼ� search ���� ������ Ƚ���� �پ���.
���� ��������� �ִ� n ������ ������� �����ǹǷ�,
O(n^2)�� �ð����⵵�� ���´�.


*/