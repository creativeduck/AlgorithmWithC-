#ifndef TMP

#include <iostream>

using namespace std;
int T, K;
int tri[1001];

void solve(int n)
{
	for (int i = 1; i < 45; i++)
	{
		for (int j = 1; j < 45; j++)
		{
			for (int k = 1; k < 45; k++)
			{
				if (tri[i] + tri[j] + tri[k] == n)
				{
					cout << 1 << '\n';
					return;
				}
			}
		}
	}
	cout << 0 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 1; i < 45; i++) tri[i] = tri[i - 1] + i;
	for (int z = 0; z < T; z++)
	{
		cin >> K;
		solve(K);
	}
	return 0;
}

#endif // !TMP

/*


*/