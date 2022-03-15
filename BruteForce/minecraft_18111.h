#ifndef MINECRAFT_18111

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int N, M, B, originB, tmp = 0, t = 128000000, height = 0, startIdx = 256, endIdx = 0;
vector<vector<int>> land;

int solve(int h)
{
	int tmpTime = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int need = h - land[i][j];
			if (need > 0)
			{
				B -= need;
				tmpTime += need;
			}
			else
			{
				B += (need * -1);
				tmpTime += (need * -1) * 2;
			}
		}
	}
	if (B < 0)
		return 128000000;
	return tmpTime;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> B;
	originB = B;
	land.assign(N, vector<int>(M, 0));
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			land[i][j] = num;
			if (num < startIdx)
			{
				startIdx = num;
			}
			if (num > endIdx)
			{
				endIdx = num;
			}
		}
	}
	// 높이 별로 구하기
	for (int i = startIdx; i <= endIdx; i++)
	{
		B = originB;
		tmp = solve(i);
		if (tmp < t)
		{
			t = tmp;
			height = i;
		}
		else if (tmp == t)
		{
			if (height < i)
			{
				height = i;
			}
		}
	}
	cout << t << " " << height;
	return 0;
}

#endif // !MINECRAFT_18111