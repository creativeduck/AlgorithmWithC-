#ifndef ALLERGY_ALGO

#include <iostream>
#include <map>	
#include <vector>
#include <algorithm>

using namespace std;
int T, n, m;
vector<vector<int>> eaters; // i��° ����� ���� �� �ִ� ���ĵ�
vector<vector<int>> foods; // i ���Ŀ� ���ؼ� ���� �� �ִ� �����
int best;


bool cmp(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}


void solve(int chosen, vector<int>& edible)
{
	if (best <= chosen) return;

	// ������ �� �Դ� �� ó�� ��� ����
	int first = 0;
	while (first < n && edible[first] > 0) first++;
	
	if (first == n)
	{
		best = chosen;
		return;
	}
	// �� ����� ���� �� �ִ� ���ĵ� ����
	// �� ���� �԰�, solve ȣ���ؼ� Ž�� �̾ ��
	for (int i = 0; i < eaters[first].size(); i++)
	{
		int food = eaters[first][i];
		// edible�� �� ������ ���� �� �ִ� ����� �߰�
		for (int j = 0; j < foods[food].size(); j++)
		{
			int people = foods[food][j];
			edible[people]++;
		}
		solve(chosen + 1, edible);
		// Ž�� ���Ŀ� ���󺹱�
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
		map<string, int> names; // � ����� ���� �� �ִ� ���� ����
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
				eaters[names[a]].push_back(i); // a ����� ���� �� �ִ� �������� i�� food �߰�
				foods[i].push_back(names[a]); // i ������ �Դ� ��� b �߰�
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
1. ������ �� �Դ� �� ù��° ����� ����.
2. �� ����� ���� ������ �� ��, ���� ���ȣ���Ѵ�.


[����]
Ž�� ���¸� �ٲٴ� �͸����ε� ����ȭ�� �� �� �ִ�.
���� ���ٹ��� ��� ��������.

*/