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
�ٷ� ���� ���� ���ô� ����, �� ���ð� �Ѿ�� ���� ������
��� ���̸� �����鼭 ����ߴ�.

�׸��� Ƚ���� 3�� ����� �Ǵ� ���,
�ٷ� ���� ���� �ٽô� ��쿡�� �׳� �� ���ð� ���� ���� �״�� �޾ƿ��� �ɷ� �ߴ�.
������ �̹��� �� ���Ŵٸ�, ������ ���̴� �� �ִ��� ���� �� �ֱ� �����̴�.

�� ������ ���� result �迭�� �����ϸ鼭 ó���ߴ�.

--����--
�׷��� ó������ ���ؼ� ��� �ϴ� ��츸 ��������,
�߰����� ������ �����ϴ� ��츦 ������� �ʾҴ�.

�׷��� �����غ���, �� ���� ���� ������ �ִ��� ���ϴ� ������� �ϸ� �ǰڴ�.
1) �̹� �����ָ� �� �԰� �״�� ���� ���
OOX ����
2) �̹� �����ָ� �Դµ�, �� ���� �����ִ� ���� �ʰ� ���� �����ִ� ���� ���
��, ������ ���� �� O�� ǥ�����ڸ�, OXO
3) �̹� �����ָ� �Դµ�, �� ���� �����ֵ� �Ծ����� ���� �����ִ� �� ���� ���
OXOO ����

���� ������ ���ڸ�
1) dp[i] = dp[i-1]
2) result[i - 2] + alcohol[i]
3) result[i - 3] + alcohol[i - 1] + alcohol[i])

�� �κ��� ������ ���� �� �� �����غ��߰ڴ�.

*/