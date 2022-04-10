#ifndef HANOI_11729

#include <iostream>

using namespace std;
int K;
// fst 에서 trd로 옮기기
void solve(int n, int fst, int sec, int trd)
{
	if (n < 1)
		return;
	// 재귀 돌리고
	solve(n - 1, fst, trd, sec);
	// 자기꺼 옮기고
	cout << fst << ' ' << trd << '\n';
	// 재귀 돌리고
	solve(n - 1, sec, fst, trd);
	return;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	cout << ((1 <<K) - 1) << '\n';
	solve(K, 1, 2, 3);
	return 0;
}

#endif // !HANOI_11729

/*
하노이는 다음 접근법을 사용한다.
맨 밑의 k번째 원을 옮기려면, k-1번째 원들을 다 다른 곳으로 옮긴 다음, k번째 원판을 옮기고,
그 이후 다시 k-1번째 원들을 다 옮기면 된다.
따라서 총 이동횟수는
a_n = 2 * a_(n-1) + 1 이 된다.
재귀적으로 하면 된다.

수행 과정을 출력하는 건 동일한 로직을 적용하면 된다.
함수
void solve(int n, int fst, int sec, int trd) 를 만들고
이것이 fst 에 있는 걸 trd 로 옮긴다라고 하면 된다.


이때 시간을 위해서 어차피 수학적 귀납법으로 하노이 풀면 2^(n-1) -1 이 나온다. 그거 비트시프트로 그냥 해줬다.
그래서 총 시간복잡도는 재귀 호출되는 만큼이고, 위 값과 동일하게 된다.
즉, 2^n의 시간복잡도를 갖는다.
*/