#ifndef HANOI_11729

#include <iostream>

using namespace std;
int K;
// fst ���� trd�� �ű��
void solve(int n, int fst, int sec, int trd)
{
	if (n < 1)
		return;
	// ��� ������
	solve(n - 1, fst, trd, sec);
	// �ڱⲨ �ű��
	cout << fst << ' ' << trd << '\n';
	// ��� ������
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
�ϳ��̴� ���� ���ٹ��� ����Ѵ�.
�� ���� k��° ���� �ű����, k-1��° ������ �� �ٸ� ������ �ű� ����, k��° ������ �ű��,
�� ���� �ٽ� k-1��° ������ �� �ű�� �ȴ�.
���� �� �̵�Ƚ����
a_n = 2 * a_(n-1) + 1 �� �ȴ�.
��������� �ϸ� �ȴ�.

���� ������ ����ϴ� �� ������ ������ �����ϸ� �ȴ�.
�Լ�
void solve(int n, int fst, int sec, int trd) �� �����
�̰��� fst �� �ִ� �� trd �� �ű�ٶ�� �ϸ� �ȴ�.


�̶� �ð��� ���ؼ� ������ ������ �ͳ������� �ϳ��� Ǯ�� 2^(n-1) -1 �� ���´�. �װ� ��Ʈ����Ʈ�� �׳� �����.
�׷��� �� �ð����⵵�� ��� ȣ��Ǵ� ��ŭ�̰�, �� ���� �����ϰ� �ȴ�.
��, 2^n�� �ð����⵵�� ���´�.
*/