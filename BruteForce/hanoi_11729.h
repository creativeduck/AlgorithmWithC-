#ifndef HANOI_11729

#include <iostream>

using namespace std;
int N;

void solve(int start, int mid, int end, int n)
{
	if (n <= 0)
		return;
	solve(start, end, mid, n - 1);
	cout << start << " " << end << '\n';
	solve(mid, start, end, n - 1);
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cout << (1 << N) -1 << '\n';
	solve(1, 2, 3, N);
	return 0;
}

#endif // !HANOI_11729

/*
�������� �ִ� n-1���� ������ 2��°�� �ű��,
������ ���� 3��°�� �ű� ����
2��° ���� 3��°�� �ű�� �� ��ǥ��.

�ٵ� ������ �� ���� �ƴϴ�. �����Ŵ�. �׷��� �̰� ������ ���� �����صΰڴ�.

*/