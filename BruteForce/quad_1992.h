#ifndef QUAD_1992

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<vector<int>> video;
string ans = "";

void compress(int y, int x, int len)
{
	//ans += "(";
	int start = video[y][x];
	for (int i = y; i < y + len; i++)
	{
		for (int j = x; j < x + len; j++)
		{
			if (start != video[i][j])
			{
				int newLen = len / 4;
				for (int k = 0; k < 4; k++)
				{
					for (int z = 0; z < 4; z++)
					{
						compress(y + newLen * k, x + newLen * z, newLen);
					}
				}

				return;
			}
		}
	}
	ans += to_string(start);
	//ans += ")";
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cout << N << endl;
	string input = "";
	for (int i = 0; i < N; i++)
	{
		vector<int> v(N, 0);
		cin >> input;
		for (int j = 0; j < N; j++)
		{
			int tmp = (int) (input[j] - '0');
			v[j] = tmp;
		}
		video.push_back(v);
	}
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << video[i][j];
	//	}
	//	cout << endl;
	//}

	compress(0, 0, N);
	cout << ans;




	return 0;
}

#endif // !QUAD_1992