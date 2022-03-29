#ifndef CODE_2011

#include <iostream>

using namespace std;
const int maxN = 1000000;
string code;
int ans = 1; // 모든 글자를 한 글자식 해석하는 경우
int len;
int dp[5001];

int solve()
{
	dp[0] = 1;
	for (int i = 1; i <= Len; i++)
	{
		if (Arr[i] >= 1 && Arr[i] <= 9)
		{
			DP[i] = (DP[i - 1] + DP[i]) % Moduler;
		}

		if (i == 1) continue;

		int Temp = Arr[i] + Arr[i - 1] * 10;
		if (Temp >= 10 && Temp <= 26)
		{
			DP[i] = (DP[i - 2] + DP[i]) % Moduler;
		}
	}



출처: https://yabmoons.tistory.com/163 [얍문's Coding World..]
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> code;
	len = code.length();
	if (len == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if ((int)code[i] - '0' == 0)
		{
			ans = 0;
		}
	}
	solve();
	cout << ans;

	return 0;
}

#endif // !CODE_2011

/*



*/