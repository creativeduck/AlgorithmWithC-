#ifndef TMP

#include <iostream>

using namespace std;
string S;

void solve()
{
	int len = S.length();
	int mid = len / 2;
	int tmpFlag = true;
	if (len % 2 == 0)
	{
		for (int i = 0; i < len - mid; i++)
		{
			if (S[mid + i] != S[mid - i - 1])
			{
				tmpFlag = false;
				break;
			}
		}
	}
	else
	{
		for (int i = 1; i < len - mid; i++)
		{
			if (S[mid + i] != S[mid - i])
			{
				tmpFlag = false;
				break;
			}
		}
	}
	if (tmpFlag)
	{
		cout << len;
		return;
	}

	for (int i = mid; i < len - 1; i++)
	{
		bool flag = true;
		int j = 1;
		for (j; (i + j < len && i - j >0); j++)
		{
			if (S[i + j] != S[i - j])
			{

				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << len + i-(j-1);
			return;
		}
		flag = true;
		for (j = 0; (i + j < len && i - j - 1 >0); j++)
		{
			if (S[i + j] != S[i - j - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << len + i-j;
			return;
		}
	}
	if (S[len-1] == S[len-2])
		cout << len + len - 2;
	else
		cout << len + len - 1;
	return;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S;
	solve();
	return 0;
}

#endif // !TMP

/*
중심이 될 수 있는지
1) mid 값 돌아가면서 확인
2) 안 될 경우 1씩 추가하면서 돌리기


*/