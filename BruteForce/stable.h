#include <iostream>

using namespace std;

const int MAXN = 1000;
int n;
// ��� i�� ���� ������ �����ϴ� �͵��� ����
int explodes[MAXN];

// ���������� ����a
bool isStable(int set)
{
	for (int i = 0; i < n; i++)
	{
		// ���� ���� set�� i�� ��Ұ� �ִٸ�(1�� i��ŭ ��Ʈ����Ʈ�ϸ� �ش� ��ġ�� �ȴ�), �˻��Ѵ�.
		// ���� set�� i�� ���� ������ �����ϴ� ������ �ִٸ�,
		// ��, i ��Ұ� �ִµ� �̰Ŷ� ���� ������ �����ϴ� ������ �ִٸ�, ���������� �ʴ�.
		if ((set & (1 << i)) && (set & explodes[i]))
			// ���������� ����
			return false;
	}
	return true;
}

int countStableSet()
{
	int ret = 0;
	for (int set = 1; set < (1 << n); set++)
	{
		// ���������� ������, continue
		if (!isStable(set)) continue;
		// Ȯ���� �� �ִ���
		bool canExtend = false;
		for (int add = 0; add < n; add++)
		{
			// ���տ� add�� ����(�׷��� and �������� �� 0�� �ǹǷ�)
			// add�� �Բ� ���� �� �����ϴ� ������ set�� ���� ���(0�� �Ǵ� ���)
			// �� �߰��� �� �ִ�. ���� �ش� ���� ������ �ƴϴ�. �̰�.
			if ((set & (1 << add)) == 0 && (explodes[add] & set) == 0)
			{
				canExtend = true;
				break;
			}
		}
		// �� �̻� Ȯ�� ���ϸ�, �߰�
		if (!canExtend)
			ret++;
	}
	return ret;
}

