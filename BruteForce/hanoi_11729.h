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
시작점에 있는 n-1개의 원판을 2번째로 옮기고,
마지막 꺼를 3번째로 옮긴 다음
2번째 꺼를 3번째로 옮기는 게 목표다.

근데 온전히 내 답이 아니다. 베낀거다. 그래서 이건 나중을 위해 저장해두겠다.

*/