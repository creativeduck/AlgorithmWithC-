#ifndef ROOM_1931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> rooms;

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int begin, end;
	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		pair<int, int> p = make_pair(end, begin);
		rooms.push_back(p);
	}
	sort(rooms.begin(), rooms.end());
	int cnt = 0, earlist = 0;
	for (int i = 0; i < N; i++)
	{
		if (earlist <= rooms[i].second)
		{
			earlist = rooms[i].first;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

#endif // !ROOM_1931

/*
� ���� ���ؼ� �װ� ��������, �տ��� ���������� �ڿ��� ���������� �־�� �Ѵ�.
�׷� � ���� �������� �� �տ� ���������̈�, �� �ڴ� ������������ �Ǻ��ؾ� �Ѵ�.

�ϴ� �θ�Ʈ������ ���ؼ� ������ �ذ��߰�,
dp�� �����ؼ� �ð��ʰ��� �����ؾ� �Ѵ�.
�׷��� Ʋ�� ������ �־���,


*/