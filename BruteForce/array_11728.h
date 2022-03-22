#ifndef ARRAY_11728

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int maxN = 2000002;
int N, M;
int arr[maxN];
int arr2[maxN];

int solution()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr2[i]);
	}
	// A와 B 배열은 이미 정렬되어있음
	int a = 0;
	int b = 0;
	while (a < N && b < M)
	{
		if (arr[a] < arr2[b])
		{
			cout << arr[a++] << " ";
		}
		else
		{
			cout << arr2[b++] << " ";
		}
	}
	while (a < N)
	{
		cout << arr[a++] << " ";
	}
	while (b < M)
	{
		cout << arr2[b++] << " ";
	}
	return 0;
}

#endif // !ARRAY_11728