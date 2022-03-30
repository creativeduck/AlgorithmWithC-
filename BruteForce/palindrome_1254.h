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
 양 끝부터 비교하면 된다.
 그럼 자연스레 가운데가 하나인 경우 그건 카운트되지 않으며, 두 개인 경우 비교가 된다.
 그리고 펠린드롬을 발견하면, 원본 문자열에 i를 더해주면 된다.
 i만큼 새로운 문자를 더해준다고 가정하고, 그 가운데 문자열을 비교했기 때문이다.

*/