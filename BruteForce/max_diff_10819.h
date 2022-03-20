#ifndef MAX_DIFF_10819

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
vector<int> A;
int absSum();

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());
	int ans = 0;
	do {
		int tmp = absSum();
		if (ans < tmp) ans = tmp;
	} while (next_permutation(A.begin(), A.end()));
	cout << ans << endl;
	return 0;
}

int absSum()
{
	int ans = 0;
	for (int i = 2; i <= A.size(); i++)
	{
		int tmp = abs(A[i - 2] - A[i - 1]);
		ans += tmp;
	}
	return ans;
}
#endif // !MAX_DIFF_10819