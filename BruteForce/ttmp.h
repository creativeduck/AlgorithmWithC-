//#ifndef BOARD_COVER_ALGO
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int T;
//int H, W, R, C;
//vector<string> board;
//int covered[10][10];
//int best;
//int blockSize;
//vector<vector<pair<int, int>>> rotation;
//
//
//vector<string> rotate(const vector<string>& arr)
//{
//	// ù��° ���� ũ�⸸ŭ ���� ũ�� �����ϰ�, �� ũ�⿡ ' ' �� ���� ä��
//	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
//	// ȸ��
//	for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = 0; j < arr[0].size(); j++)
//		{
//			ret[j][arr.size() - i - 1] = arr[i][j];
//		}
//	}
//	return ret;
//}
//// �� 90���� �����鼭 �� ���� ��� �������� �� ��ǥ�� �����ϱ�
//void generateRotation(vector<string>& block)
//{
//	rotation.clear();
//	rotation.resize(4);
//	for (int rot = 0; rot < 4; rot++)
//	{
//		int originY = -1, originX = -1;
//		for (int i = 0; i < block.size(); i++)
//		{
//			for (int j = 0; j < block[i].size(); j++)
//			{
//				if (block[i][j] == '#')
//				{
//					if (originY == -1)
//					{
//						originY = i;
//						originX = j;
//					}
//					rotation[rot].push_back(make_pair(i - originY, j - originX));
//				}
//			}
//		}
//		block = rotate(block);
//	}
//	// �ߺ��� �͵� �������ֱ�
//	sort(rotation.begin(), rotation.end());
//	rotation.erase(unique(rotation.begin(), rotation.end()), rotation.end());
//	blockSize = rotation[0].size();
//}
//
//bool set(int y, int x, const vector<pair<int, int>>& block, int delta)
//{
//	int ret = true;
//	for (int i = 0; i < block.size(); i++)
//	{
//		int ny = y + block[i].first;
//		int nx = x + block[i].second;
//		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
//			ret = false;
//		// �ϴ� ��� �����ְų� ���ֱ�
//		else if ((covered[ny][nx] += delta) > 1)
//			ret = false;
//	}
//	return ret;
//}
//// ���� ���� �����/���ũ�� + ���� ���� ��ϰ����� �����غ��� �۰ų� ���ٸ�, �� �̻� �� �ʿ� �����Ƿ� ���ϱ�
//int pruning(int placed)
//{
//	int emptys = 0;
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			if (covered[i][j] == 0)
//				emptys++;
//		}
//	}
//	return (emptys / blockSize) + placed <= best ? true : false;
//}
//
//void search(int placed)
//{
//	// ����ġ��
//	if (pruning(placed)) return;
//	int y = -1, x = -1;
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			if (covered[i][j] == 0)
//			{
//				y = i;
//				x = j;
//				break;
//			}
//		}
//		if (y != -1) break;
//	}
//	// �� ������ ������ ��ȯ
//	if (y == -1)
//	{
//		best = max(best, placed);
//		return;
//	}
//	for (int i = 0; i < rotation.size(); i++)
//	{
//		if (set(y, x, rotation[i], 1))
//			search(placed + 1);
//		set(y, x, rotation[i], -1);
//	}
//	// �ϴ� ���Ƴ���
//	covered[y][x] = 1;
//	search(placed);
//	// Ǯ���ֱ�
//	covered[y][x] = 0;
//}
//
//int solve()
//{
//	best = 0;
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
//	}
//	search(0);
//	return best;
//}
//
//int solution()
//{
//	freopen("input.txt", "r", stdin);
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> T;
//	for (int t = 0; t < T; t++)
//	{
//		board.clear();
//		cin >> H >> W >> R >> C;
//		string tmpC;
//		vector<string> block;
//		for (int h = 0; h < H; h++)
//		{
//			cin >> tmpC;
//			board.push_back(tmpC);
//		}
//		for (int r = 0; r < R; r++)
//		{
//			cin >> tmpC;
//			block.push_back(tmpC);
//		}
//		generateRotation(block);
//		cout << solve() << '\n';
//	}
//
//
//	return 0;
//}
//
//#endif // !BOARD_COVER_ALGO
//
///*
//1. ȸ���� ����� �迭 ���ϱ�
//2. �� ��ġ���� ��� ǥ���� ��, ���ȣ��� �ִ� ���� ���ϱ�
//3. ����ȭ�ϱ�
//
//������ �־������� ����ü ���� �Ҹ��� ������.
//�ϴ� ���ش� ����.
//�׷��� ������ �ٽ� Ǯ��.
//
//
//*/