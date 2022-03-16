#ifndef MAKE_CRYPTO_1759

#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int L, C;
vector<char> words;
char answer[15];

void solve(int start, int depth)
{
	if (depth == L)
	{
		int mo = 0;
		int ja = 0;
		for (int i = 0; i < L; i++)
		{
			char alpha = answer[i];
			if (alpha == 'a' || alpha == 'e' || alpha == 'u' || alpha == 'i' || alpha == 'o')
			{
				mo++;
			}
			else 
			{
				ja++;
			}
		}
		if (mo >= 1 && ja >= 2)
		{
			for (int i = 0; i < L; i++)
			{
				cout << answer[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = start; i < C; i++)
	{
		answer[depth] = words[i];
		solve(i + 1, depth + 1);
	}
}

int solution()
{
	freopen("input.txt", "r", stdin);
	cin >> L >> C;
	words.assign(C, 'a');
	for (int i = 0; i < C; i++)
	{
		cin >> words[i];
	}
	sort(words.begin(), words.end());
	solve(0, 0);
	return 0;
}

#endif // !MINECRAFT_18111