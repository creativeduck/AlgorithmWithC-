#ifndef STICKER_9465

#include <iostream>

using namespace std;
const int maxN = 100001;
int T, n;
int st[2][maxN];
int result[maxN][3];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> st[j][k];
			}
		}
		result[0][0] = st[0][0]; // 아래
		result[0][1] = st[1][0]; // 위
		result[0][2] = 0;		 // X
		for (int i = 1; i < n; i++)
		{
			result[i][0] = max(result[i - 1][1], result[i-1][2]) + st[0][i];
			result[i][1] = max(result[i - 1][0], result[i-1][2]) + st[1][i];
			result[i][2] = max(result[i - 1][0], result[i - 1][1]);
		}
		cout << max(result[n-1][0], result[n-1][1]) << endl;
	}
	return 0;
}

#endif // !STICKER_9465

/*
난 일단 완전 탐색 방법을 사용해서 문제를 접근했다.
이걸 어떻게 dp로 엮을지는 아직 떠오르지 않는다.

계속 고민하다보니,
위, 아래, 아무것도 안함 이렇게 세 단계로 나누어서 계속 생각할 수 있다고 판단했다.
그리고 밑으로 내려오면서는
위에껀 아래꺼나 아무것도 안함 중에서 큰 것을,
아래껀 위에꺼나 아무것도 안함 중에서 큰 것을,
아무것도 안함은 이전 것중에서 가장 큰 값을,
갖도록 했다.

그리고 계속 depth를 높여가면서 하면 된다.

시간복잡도는 입력을 받는 거나 테스트 케이스 받는 것을 고려하지 않는다면,
계산 자체는 n까지의 반복문 하나에 계속 max만 해주는 것이므로,
사실상 O(N)이 된다.
즉, 매우 빠르다.
*/