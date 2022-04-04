#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int N;
double maxVal = 0;

int solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> x(N);
	vector<int> y(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				double S = abs((x[i] * y[j] + x[j] * y[k] + x[k] * y[i]) - (x[j] * y[i] + x[k] * y[j] + x[i] * y[k]));
				if (maxVal < S)
					maxVal = S;
			}
		}
	}
	printf("%0.1f", maxVal / 2);
	return 0;
}