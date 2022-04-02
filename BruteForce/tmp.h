#ifndef TMP

#include <iostream>
#include <algorithm>

using namespace std;
int T, N, ans = 0;
int dice[100000];

void pushLast(int arr[],int target,int size)
{
	int tmp = arr[target];
	for (int i = target; i < size-1; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = tmp;
}

int solution()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
			cin >> dice[n];
		sort(dice, dice+N);
		int d = N;
		while (d > 1)
		{
			bool flag = true;
			for (int i=0; i < d; i++)
			{
				if (dice[i] < i + 1)
				{
					pushLast(dice, i, N);
					flag = false;
					break;
				}
			}
			if (flag)
				break;
			else
				d--;
		}
		cout << "Case #" << t + 1 << ": " << d << '\n';
	}
	return 0;
}

#endif // !TMP

/*
중심이 될 수 있는지
1) mid 값 돌아가면서 확인
2) 안 될 경우 1씩 추가하면서 돌리기


*/