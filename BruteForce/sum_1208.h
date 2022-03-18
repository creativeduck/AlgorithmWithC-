#ifndef SUM_1208

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, S, half, cnt=0;
long long ans=0;
vector<int> nums;
map<int, int> maps;
int answer[40] = { 0, };


void solveLeft(int depth, int sum)
{
	if (depth == half)
	{
		maps[sum]++; return;
	}
	solveLeft(depth + 1, sum);
	solveLeft(depth + 1, sum + nums[depth]);
}

void solveRight(int depth, int sum)
{
	if (depth == N)
	{
		ans += maps[S - sum]; return;
	}
	solveRight(depth + 1, sum);
	solveRight(depth + 1, sum + nums[depth]);
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> N >> S;
	half = N / 2;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		nums.push_back(n);
	}
	solveLeft(0, 0);
	solveRight(half, 0);
	if (S == 0) ans--;
	cout << ans;
	return 0;
}

#endif // !SUM_1208