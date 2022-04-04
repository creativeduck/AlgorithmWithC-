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
어떤 수에 대해서 그걸 기준으로, 앞에는 오름차순과 뒤에는 내림차순이 있어야 한다.
그럼 어떤 수를 기준으로 그 앞엔 오름차순이닞, 그 뒤는 내림차순인지 판별해야 한다.

일단 부르트포스를 통해서 문제를 해결했고,
dp를 적용해서 시간초과를 방지해야 한다.
그런데 틀린 로직이 있었고,


*/