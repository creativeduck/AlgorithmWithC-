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
//	// 첫번째 문자 크기만큼 벡터 크기 설정하고, 그 크기에 ' ' 로 가득 채움
//	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
//	// 회전
//	for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = 0; j < arr[0].size(); j++)
//		{
//			ret[j][arr.size() - i - 1] = arr[i][j];
//		}
//	}
//	return ret;
//}
//// 블럭 90도씩 돌리면서 맨 왼쪽 상단 기준으로 블럭 좌표들 저장하기
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
//	// 중복된 것들 제거해주기
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
//		// 일단 블록 놓아주거나 빼주기
//		else if ((covered[ny][nx] += delta) > 1)
//			ret = false;
//	}
//	return ret;
//}
//// 만일 남은 빈공간/블록크기 + 현재 놓인 블록개수가 최적해보다 작거나 같다면, 더 이상 할 필요 없으므로 안하기
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
//	// 가지치기
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
//	// 다 됐으면 최적해 반환
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
//	// 일단 막아놓기
//	covered[y][x] = 1;
//	search(placed);
//	// 풀어주기
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
//1. 회전된 블록을 배열 구하기
//2. 각 위치에서 블록 표시한 후, 재귀호출로 최대 갯수 구하기
//3. 최적화하기
//
//정답이 있었음에도 도대체 무슨 소린지 몰랐다.
//일단 이해는 간다.
//그러니 다음에 다시 풀자.
//
//
//*/