#ifndef GRADUATE_ALGO

#include <iostream>

using namespace std;
const int maxN = 987654321;


int T, N, K, M, L, R, C;
// i��° ������ ��������� ����
int prerequisite[12];
// i��° �б⿡ ������ ���� ��
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
	cin >> T; // �׽�Ʈ���̽� ����
	while (T > 0)
	{
		memset(dp, -1, sizeof(dp));
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		
		// N�� �������� ��
		// K�� ���� �� ���� ��
		// M�� �б� ��
		// L�� �� �б⿡ �ִ�� ���� �� �ִ� �����
		cin >> N >> K >> M >> L; 
		// �� �����, �� ���� ���� ��������� �ޱ�
		
		for (int n = 0; n < N; n++)
		{
			cin >> R; // R�� n�� ���� ���� �������� ��
			for (int r = 0; r < R; r++)
			{
				int subject;
				cin >> subject;
				prerequisite[n] |= (1 << subject);
			}
		}
		// �̹� �б���� ������� �� �б��� ���� �ޱ�
		for (int m = 0; m < M; m++)
		{
			cin >> C; // m�� �б⿡ �����Ǵ� �����
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
// semester �� ���� �б�, taken �� ���ݱ��� ���� ������ ����
// graduate �� ������ �ٳ�� �ϴ� �ּ� �б� ���� ��ȯ�Ѵ�.
int graduate(int semester, int taken)
{
	// �� ����ٸ�, 0 ��ȯ
	if (bitCount(taken) >= K) return 0;
	// �б� �� �����µ� ������ ���� �ִٸ�, ��û ū ���� ��ȯ
	if (semester == M) return  maxN;

	int& ret = dp[semester][taken];
	if (ret != -1) return ret;
	ret = maxN;
	// �̹� �б� ���� �� ���� �� ���� ���� �����
	int canTake = (classes[semester] & ~taken);
	// ���������� �� �� ���� �� �����ϴ� ������� ��� �����ϱ�
	for (int i = 0; i < N; i++)
	{	
		// 1) ���� i�� ������ ���� �ϰ�
		// 2) i�� ������ ���������� �� ���� ���
		// (i���� ���� �������� ���հ� ����� ����� and �����ϸ�, i�� �������� ������ ���;� �Ѵ�. �׷��� �� ����������� ��� ����⿡ 1�� ǥ�õǴ� ���̹Ƿ�)
		if ((canTake & (1 << i)) &&
			(taken & prerequisite[i]) != prerequisite[i])
			// �����ϱ�
			canTake &= ~(1 << i);
	}
	// �� ������ ��� �κ� ��ȸ�ϱ�
	for (int take = canTake; take > 0; take = ((take - 1) & canTake))
	{
		if (bitCount(take) > L) continue; // ���� �б⿡ ���� �� �ִ� ���� ���� �ʰ��ϸ�, continue
		// ���簪�� ���ؼ� �ּڰ�
		// �� �б�(+1) �ٴϰ�, taken�� �̹��� ���� ����� or �������� �����ֱ�
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	// �̹� �б⿡ �ƹ��͵� �� ���� ���
	ret = min(ret, graduate(semester + 1, taken));
	return ret;



}

// n�� ���������� ���� ��Ʈ�� ���� ��ȯ
int bitCount(int n)
{
	if (n == 0)
		return 0;
	return n % 2 + bitCount(n / 2);
}
#endif // !GRADUATE_ALGO

/*



*/