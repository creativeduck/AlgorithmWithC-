#ifndef MATH_19532

#include <iostream>

using namespace std;
int a, b, c, d, e, f;

int solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> c >> d >> e >> f;
	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if (a * x + b * y == c && d * x + e * y == f)
				cout << x << " " << y;
		}
	}
	return 0;
}

#endif // !MATH_19532

/*


*/