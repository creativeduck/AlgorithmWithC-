#ifndef ALLERGY_ALGO

#include <iostream>
#include <map>	
#include <vector>
#include <algorithm>

using namespace std;
int T, n, m;
vector<vector<int>> eaters; // i번째 사람이 먹을 수 있는 음식들
vector<vector<int>> foods; // i 음식에 대해서 먹을 수 있는 사람들
int best;


bool cmp(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}


void solve(int chosen, vector<int>& edible)
{
	if (best <= chosen) return;

	// 음식을 못 먹는 맨 처음 사람 고르기
	int first = 0;
	while (first < n && edible[first] > 0) first++;
	
	if (first == n)
	{
		best = chosen;
		return;
	}
	// 그 사람이 먹을 수 있는 음식들 나열
	// 각 음식 먹고, solve 호출해서 탐색 이어서 함
	for (int i = 0; i < eaters[first].size(); i++)
	{
		int food = eaters[first][i];
		// edible에 이 음식을 먹을 수 있는 사람들 추가
		for (int j = 0; j < foods[food].size(); j++)
		{
			int people = foods[food][j];
			edible[people]++;
		}
		solve(chosen + 1, edible);
		// 탐색 이후엔 원상복귀
		for (int j = 0; j < foods[food].size(); j++)
		{
			int people = foods[food][j];
			edible[people]--;
		}
	}
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
		cin >> n >> m;
		map<string, int> names; // 어떤 사람이 먹을 수 있는 음식 종류
		string name;
		for (int i = 0; i < n; i++)
		{
			cin >> name;
			names[name] = i;
		}
		eaters.clear();
		eaters.resize(n);
		foods.clear();
		foods.resize(m);
		int food; string a; string b;
		for (int i = 0; i < m; i++)
		{
			cin >> food;
			for (int j = 0; j < food; j++)
			{
				string a;
				cin >> a;
				eaters[names[a]].push_back(i); // a 사람이 먹을 수 있는 음식으로 i번 food 추가
				foods[i].push_back(names[a]); // i 음식을 먹는 사람 b 추가
			}
		}
		best = m;
		vector<int> edible(n, 0);
		solve(0, edible);
		cout << best << '\n';
	}
	return 0;
}

#endif // !ALLERGY_ALGO

/*
1. 음식을 못 먹는 맨 첫번째 사람을 고른다.
2. 그 사람이 먹을 음식을 고른 뒤, 각각 재귀호출한다.


[여담]
탐색 형태를 바꾸는 것만으로도 최적화를 할 수 있다.
따라서 접근법도 계속 생각하자.

*/