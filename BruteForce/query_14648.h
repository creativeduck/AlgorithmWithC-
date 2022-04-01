#ifndef QUERY_14648

#include <iostream>
#include <vector>

using namespace std;
int n, q;
int v[1001];

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int type, a, b, c, d;
	long ans;
	for (int i = 0; i < q; i++)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> a >> b;
			ans = 0;
			for (int k = --a; k < b; k++)
			{
				ans += v[k];
			}
			cout << ans << endl;
			long tmp = v[a];
			v[a] = v[--b];
			v[b] = tmp;
		}
		else
		{
			cin >> a >> b >> c >> d;
			ans = 0;
			for (int k = --a; k < b; k++)
			{
				ans += v[k];
			}
			for (int k = --c; k < d; k++)
			{
				ans -= v[k];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}

#endif // !QUERY_14648

/*

*/