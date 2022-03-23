#ifndef ALCOHOL_2156

#include <iostream>

using namespace std;
const int maxN = 10001;
int n;
int alcohol[maxN];
int result[maxN];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> alcohol[i];
	}
	result[0] = 0; result[1] = alcohol[1]; result[2] = alcohol[1] + alcohol[2];
	for (int i = 3; i <= n; i++)
	{
		result[i] = result[i - 1];
		int tmp = max(result[i - 2] + alcohol[i], result[i - 3] + alcohol[i - 1] + alcohol[i]);
		result[i] = max(tmp, result[i]);
	}
	cout << result[n] << '\n';
	return 0;
}

#endif // !ALCOHOL_2156

/*
바로 다음 잔을 마시는 경우와, 안 마시고 넘어가는 경우로 나눠서
계속 깊이를 깊여가면서 계산했다.

그리고 횟수가 3의 배수가 되는 경우,
바로 다음 잔을 바시는 경우에선 그냥 안 마시고 이전 값을 그대로 받아오는 걸로 했다.
어차피 이번에 안 마신다면, 이전에 마셨던 게 최댓값을 만들 수 있기 때문이다.

이 값들을 따로 result 배열에 저장하면서 처리했다.

--오답--
그러나 처음부터 더해서 계속 하는 경우만 생각헀고,
중간부터 덧셈을 시작하는 경우를 고려하지 않았다.

그래서 생각해보니, 세 가지 경우로 나눠서 최댓값을 구하는 방식으로 하면 되겠다.
1) 이번 포도주를 안 먹고 그대로 오는 경우
OOX 상태
2) 이번 포도주를 먹는데, 그 이전 포도주는 먹지 않고 전전 포도주는 먹은 경우
즉, 포도주 먹은 걸 O로 표시하자면, OXO
3) 이번 포도주를 먹는데, 그 이전 포도주도 먹었지만 전전 포도주는 안 먹은 경우
OXOO 상태

각각 식으로 보자면
1) dp[i] = dp[i-1]
2) result[i - 2] + alcohol[i]
3) result[i - 3] + alcohol[i - 1] + alcohol[i])

각 부분을 나누는 것을 좀 더 공부해봐야겠다.

*/