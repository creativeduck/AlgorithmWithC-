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

// 블록 돌린 것 반환하는 함수
vector<string> rotate(const vector<string>& block)
{
	// block 벡터의 크기만큼, 그리고 각 문자열은 block 벡터의 문자열의 크기만큼
	vector<string> rot(block[0].size(), string(block.size(), ' '));
	for (int i = 0; i < block.size(); i++)
	{
		for (int j = 0; j < block[0].size(); j++)
			rot[j][block.size() - i - 1] = block[i][j];
	}
	return rot;
}

// 각 로테이션한 블록 만드는 함수 - 각 로테이션에는 덮어야 하는, 즉 '.'인 곳의 상대좌표를 다 넣어줌
void generateRotations(vector<string>& block)
{
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++)
	{
		int originY = -1, originX = -1; // 맨 위 왼쪽 좌표를 시작점으로 잡음
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
		// 90도 회전
		block = rotate(block);
	}
	// 중복된 것 있으면 제거해주기
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size(); 	
}


// 보드에 블록 놓고 빼는 함수
bool set(int y, int x, const vector<pair<int, int>>& rotation, int delta)
{
	bool ret = true;
	for (int i = 0; i < rotation.size(); i++)
	{
		int ny = y + rotation[i].first;
		int nx = x + rotation[i].second;
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) // 좌표 범위 벗어나면 안 됨
			ret = false;
		// 일단 블록을 덮는데, 덮어진 이후 값이 1보다 커지면 안 됨
		else if ((covered[ny][nx] += delta) > 1)
			ret = false;
	}
	// 잘 덮여졌다면, true 반환
	return ret;
}
// 가지치기
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

// 현재 블록 놓은 개수를 매개변수로 받음
void search(int placed)
{
	if (pruning(placed))
		return;
	int y = -1, x = -1;
	// 덮을 수 있는 맨 위 왼쪽 좌표 찾기
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

	// 덮을 곳이 없다면, 반환
	if (y == -1)
	{
		best = max(best, placed);
		return;
	}

	for (int rot = 0; rot < rotations.size(); rot++)
	{
		// 덮은 다음 탐색하기
		if (set(y, x, rotations[rot], 1))
			search(placed + 1);
		// 다시 빼주기
		set(y, x, rotations[rot], -1);
	}

	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}


int solve()
{
	best = 0;
	// 이미 덮여진 곳은 1로 표시
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
1. 각 블록 회전한 것들(총 4개) 배열 만들기
2. 맨 왼쪽 위쪽부터 시작해서 블록 채우기
3. 최적화하기
현재 남은 빈 공간/블록크기 + 현재 블록크기 <= 최적해 라면, 가지치기

결국 성공은 했다.
배열의 크기도 각각 동적으로 주는 것도 굉장히 중요하다.


set에서 n제곱번 수행하면, 이후 search 에선 수행을 안 해도 된다.
즉, set에서 한 횟수에 비례해서 search 에서 수행할 횟수가 줄어든다.
따라서 결과적으로 최대 n 제곱의 연산들이 나열되므로,
O(n^2)의 시간복잡도를 갖는다.


*/