#ifndef SUM_1912

#include <iostream>

using namespace std;
const int maxN = 100001;
int sums[maxN];
int N;

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> sums[i];
	int maxVal = -1000;
	for (int i = 0; i < N; i++)
	{
		sums[i] = max(sums[i], sums[i] + sums[i - 1]);
		if (sums[i] > maxVal)
			maxVal = sums[i];
	}
	cout << maxVal;
	return 0;
}

#endif // !SUM_1912

/*
일단 0번째 인덱스에서 모두 더해준 다음,
그 값들을 기준으로 다른 인덱스들에서 처리를 해주었다.


-- 시간초과가 발생했다.
아무래도 사실상 dp를 쓰긴 쓰지만 그럼에도 연산을 많이 해야 해서 그런가보다.

정말 간단한 dp가 있었다.
현재 값은 그 이전 연속된 값을 더한 것과 현재 값 중 최댓값으로 하면 되는데...
앞으론 마냥 코드를 짜지 말고, 먼저 논리를 최대한 생각해보자.
최소 10분은 스튜디오를 잡지 말자.

*/