#ifndef REMOTE_1107

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> wrongs(10, 0);

int solution()
{
	freopen("input.txt", "r", stdin);
	int N, M, w, minVal, cnt = 0;
	cin >> N >> M;
	minVal = abs(N - 100);
	for (int i = 0; i < M; i++)
	{
		cin >> w, wrongs[w] = true;
	}
	for (int num = 0; num <= 1000000; num++)
	{
		string numStr = to_string(num);
		bool isWrong = false;
		for (int i = 0; i < numStr.length(); i++)
		{
			if (wrongs[numStr[i] - '0'])
			{
				isWrong = true;
				break;
			}
		}
		if (!isWrong)
		{
			int left = abs(N - num);
			cnt = left + to_string(num).length();
			if (cnt < minVal)
			{
				minVal = cnt;
			}
		}
	}
	cout << minVal << endl;
	return 0;
}

#endif // !REMOTE_1107