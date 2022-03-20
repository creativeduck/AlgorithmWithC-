#ifndef SQUARE_1451

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long getSum(int startX, int endX, int startY, int endY);

int N, M;
long long Max = 0;
vector<vector<int>> square;

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	square.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		string nums;
		cin >> nums;
		for (int j = 0; j < M; j++)
		{
			int tmp = nums[j] - '0';
			square[i][j] = tmp;
		}
	}
	// 1번
	for (int i = 0; i < M - 2; i++)
	{
		for (int j = i + 1; j < M - 1; j++)
		{
			long long num1 = getSum(0, i, 0, N - 1);
			long long num2 = getSum(i + 1, j, 0, N - 1);
			long long num3 = getSum(j + 1, M - 1, 0, N - 1);
			Max = max(Max, num1 * num2 * num3);
		}
	}
	// 2번
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			long long num1 = getSum(0, M - 1, 0, i);
			long long num2 = getSum(0, M - 1, i + 1, j);
			long long num3 = getSum(0, M - 1, j + 1, N - 1);
			Max = max(Max, num1 * num2 * num3);
		}
	}
	// 3번
	for (int i = 0; i < M - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			long long num1 = getSum(0, i, 0, N - 1);
			long long num2 = getSum(i + 1, M - 1, 0, j);
			long long num3 = getSum(i + 1, M - 1, j + 1, N - 1);
			Max = max(Max, num1 * num2 * num3);
		}
	}
	// 4번
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			long long num1 = getSum(0, M - 1, 0, i);
			long long num2 = getSum(0, j, i + 1, N - 1);
			long long num3 = getSum(j + 1, M - 1, i + 1, N - 1);
			Max = max(Max, num1 * num2 * num3);
		}
	}
	// 5번
	for (int i = 0; i < M - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			long long num1 = getSum(0, i, 0, j);
			long long num2 = getSum(0, i, j + 1, N - 1);
			long long num3 = getSum(i + 1, M - 1, 0, N - 1);
			Max = max(Max, num1 * num2 * num3);
		}
	}
	// 6번
	for (int i = 0; i < M - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			long long num1 = getSum(0, i, 0, j);
			long long num2 = getSum(i + 1, M - 1, 0, j);
			long long num3 = getSum(0, M - 1, j + 1, N - 1);
			Max = max(Max, num1 * num2 * num3);
		}
	}
	cout << Max << endl;
	return 0;
}
long long getSum(int startX, int endX, int startY, int endY)
{
	long long num = 0;
	for (int i = startX; i <= endX; i++)
	{
		for (int j = startY; j <= endY; j++)
		{
			num += square[j][i];
		}
	}
	return num;
}

#endif // !SQUARE_1451