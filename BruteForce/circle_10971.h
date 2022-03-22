#ifndef DATE_1476

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
vector<vector<int>> costs;
vector<int> cities;

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> pays(N, 0);
		for (int j = 0; j < N; j++)
		{
			int city;
			cin >> city, pays[j] = city;
		}
		costs.push_back(pays);
		cities.push_back(i);
	}
	int ans = 5000000;
	do {
		int cost = 0;
		for (int i = 0; i < N; i++)
		{
			int cur = cities[i];
			int next;
			if (i == N - 1)
				next = cities[0];
			else
				next = cities[i + 1];
			int tmp = costs[cur][next];
			if (tmp == 0)
			{
				cost = 5000000;
				break;
			}
			cost += tmp;
		}
		ans = min(ans, cost);
	} while (next_permutation(cities.begin(), cities.end()));
	cout << ans;
	return 0;
}

#endif // !DATE_1476