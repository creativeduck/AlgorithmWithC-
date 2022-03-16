#ifndef DATE_1476

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution()
{
	freopen("input.txt", "r", stdin);
	int e, s, m;
	int eLeft, sLeft, mLeft;
	cin >> e >> s >> m;
	int n = 1;
	while (1)
	{
		eLeft = n % 15;
		if (eLeft == 0) eLeft = 15;
		sLeft = n % 28;
		if (sLeft == 0) sLeft = 28;
		mLeft = n % 19;
		if (mLeft == 0) mLeft = 19;
		if (e == eLeft && s == sLeft && m == mLeft)
		{
			cout << n << endl;
			break;
		}
		else n++;
	}
	return 0;
}

#endif // !DATE_1476