#ifndef GRADUATE_ALGO

#include <iostream>

using namespace std;
const int maxN = 987654321;


int T, N, K, M, L, R, C;
// i번째 과목의 선수과목들 집합
int prerequisite[12];
// i번째 학기에 열리는 과목 수
int classes[10];
int dp[10][1<<12];

int bitCount(int n);
int graduate(int semester, int taken);
void init();

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T; // 테스트케이스 개수
	while (T > 0)
	{
		memset(dp, -1, sizeof(dp));
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		
		// N은 전공과목 수
		// K는 들어야 할 과목 수
		// M은 학기 수
		// L은 한 학기에 최대로 들을 수 있는 과목수
		cin >> N >> K >> M >> L; 
		// 각 과목과, 그 과목에 대한 선수과목들 받기
		
		for (int n = 0; n < N; n++)
		{
			cin >> R; // R은 n번 과목에 대한 선수과목 수
			for (int r = 0; r < R; r++)
			{
				int subject;
				cin >> subject;
				prerequisite[n] |= (1 << subject);
			}
		}
		// 이번 학기부터 순서대로 각 학기의 정보 받기
		for (int m = 0; m < M; m++)
		{
			cin >> C; // m번 학기에 개설되는 과목수
			for (int c = 0; c < C; c++)
			{
				int cl;
				cin >> cl;
				classes[m] |= (1 << cl);
			}
		}
		int ans = 0;
		ans = graduate(0, 0);
		if (ans == maxN)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
		T--;
	}
	

	return 0;
}
// semester 는 현재 학기, taken 은 지금까지 들은 과목의 집합
// graduate 는 앞으로 다녀야 하는 최소 학기 수를 반환한다.
int graduate(int semester, int taken)
{
	// 다 들었다면, 0 반환
	if (bitCount(taken) >= K) return 0;
	// 학기 다 끝났는데 못들은 과목 있다면, 엄청 큰 숫자 반환
	if (semester == M) return  maxN;

	int& ret = dp[semester][taken];
	if (ret != -1) return ret;
	ret = maxN;
	// 이번 학기 과목 중 아직 못 들은 과목만 남기기
	int canTake = (classes[semester] & ~taken);
	// 선수과목을 못 들어서 현재 못 수강하는 과목들은 모두 제외하기
	for (int i = 0; i < N; i++)
	{	
		// 1) 현재 i번 과목을 들어야 하고
		// 2) i번 과목의 선수과목을 못 들은 경우
		// (i번에 대한 선수과목 집합과 들었던 과목들 and 연산하면, i번 선수과목 집합이 나와야 한다. 그래야 그 선수과목들을 모두 들었기에 1로 표시되는 것이므로)
		if ((canTake & (1 << i)) &&
			(taken & prerequisite[i]) != prerequisite[i])
			// 제외하기
			canTake &= ~(1 << i);
	}
	// 이 집합의 모든 부분 순회하기
	for (int take = canTake; take > 0; take = ((take - 1) & canTake))
	{
		if (bitCount(take) > L) continue; // 현재 학기에 들을 수 있는 과목 수를 초과하면, continue
		// 현재값과 비교해서 최솟값
		// 한 학기(+1) 다니고, taken에 이번에 들은 과목들 or 연산으로 더해주기
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	// 이번 학기에 아무것도 안 들은 경우
	ret = min(ret, graduate(semester + 1, taken));
	return ret;



}

// n의 이진수에서 켜진 비트의 수를 반환
int bitCount(int n)
{
	if (n == 0)
		return 0;
	return n % 2 + bitCount(n / 2);
}
#endif // !GRADUATE_ALGO

/*



*/