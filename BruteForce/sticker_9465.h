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
		result[0][0] = st[0][0]; // �Ʒ�
		result[0][1] = st[1][0]; // ��
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
�� �ϴ� ���� Ž�� ����� ����ؼ� ������ �����ߴ�.
�̰� ��� dp�� �������� ���� �������� �ʴ´�.

��� ����ϴٺ���,
��, �Ʒ�, �ƹ��͵� ���� �̷��� �� �ܰ�� ����� ��� ������ �� �ִٰ� �Ǵ��ߴ�.
�׸��� ������ �������鼭��
������ �Ʒ����� �ƹ��͵� ���� �߿��� ū ����,
�Ʒ��� �������� �ƹ��͵� ���� �߿��� ū ����,
�ƹ��͵� ������ ���� ���߿��� ���� ū ����,
������ �ߴ�.

�׸��� ��� depth�� �������鼭 �ϸ� �ȴ�.

�ð����⵵�� �Է��� �޴� �ų� �׽�Ʈ ���̽� �޴� ���� ������� �ʴ´ٸ�,
��� ��ü�� n������ �ݺ��� �ϳ��� ��� max�� ���ִ� ���̹Ƿ�,
��ǻ� O(N)�� �ȴ�.
��, �ſ� ������.
*/