#ifndef PALINDROME_1254

#include <iostream>

using namespace std;
string S;
bool solve(string s)
{
	bool flag = true;
	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] != s[s.length()-1-i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S;
	n = S.length();
	for (int i = 0; i < S.length(); i++)
	{
		string tmp = S.substr(i, S.length());
		if (solve(tmp))
		{
			cout << i + S.length();
			break;
		}
	}
	return 0;
}

#endif // !PALINDROME_1254

/*
 �� ������ ���ϸ� �ȴ�.
 �׷� �ڿ����� ����� �ϳ��� ��� �װ� ī��Ʈ���� ������, �� ���� ��� �񱳰� �ȴ�.
 �׸��� �縰����� �߰��ϸ�, ���� ���ڿ��� i�� �����ָ� �ȴ�.
 i��ŭ ���ο� ���ڸ� �����شٰ� �����ϰ�, �� ��� ���ڿ��� ���߱� �����̴�.

*/