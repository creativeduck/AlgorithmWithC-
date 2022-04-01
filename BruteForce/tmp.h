#ifndef TMP

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxN = 101;
int T, N;
int ans=0;

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vector<int> v(N, 0);
		for (int n = 0; n < N; n++)
		{
			cin >> v[n];
		}
		for (int i = 0; i < v.size() - 1; i++)
		{
			int minIdx = i;
			int minVal = INT_MAX;
			for (int k = i; k < v.size(); k++)
			{
				if (minVal > v[k])
				{
					minVal = v[k];
					minIdx = k;
				}
			}
			reverse(v.begin() + i, v.begin() + minIdx+1);
			ans += (minIdx - i + 1);
		}
		cout << "Case #" << t + 1 << ": " << ans << '\n';
		ans = 0;
	}
	return 0;
}

#endif // !TMP

/*
�߽��� �� �� �ִ���
1) mid �� ���ư��鼭 Ȯ��
2) �� �� ��� 1�� �߰��ϸ鼭 ������


*/