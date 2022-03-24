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
�ϴ� 0��° �ε������� ��� ������ ����,
�� ������ �������� �ٸ� �ε����鿡�� ó���� ���־���.


-- �ð��ʰ��� �߻��ߴ�.
�ƹ����� ��ǻ� dp�� ���� ������ �׷����� ������ ���� �ؾ� �ؼ� �׷�������.

���� ������ dp�� �־���.
���� ���� �� ���� ���ӵ� ���� ���� �Ͱ� ���� �� �� �ִ����� �ϸ� �Ǵµ�...
������ ���� �ڵ带 ¥�� ����, ���� ���� �ִ��� �����غ���.
�ּ� 10���� ��Ʃ����� ���� ����.

*/