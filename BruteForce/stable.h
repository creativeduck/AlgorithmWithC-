#include <iostream>

using namespace std;

const int MAXN = 1000;
int n;
// 요소 i랑 같이 있으면 폭발하는 것들의 집합
int explodes[MAXN];

// 안정적인지 여부a
bool isStable(int set)
{
	for (int i = 0; i < n; i++)
	{
		// 만약 집합 set에 i번 요소가 있다면(1을 i만큼 비트시프트하면 해당 위치가 된다), 검사한다.
		// 만약 set에 i랑 같이 있으면 폭발하는 물질이 있다면,
		// 즉, i 요소가 있는데 이거랑 같이 있으면 폭발하는 물질도 있다면, 안정적이지 않다.
		if ((set & (1 << i)) && (set & explodes[i]))
			// 안정적이지 않음
			return false;
	}
	return true;
}

int countStableSet()
{
	int ret = 0;
	for (int set = 1; set < (1 << n); set++)
	{
		// 안정적이지 않으면, continue
		if (!isStable(set)) continue;
		// 확장할 수 있는지
		bool canExtend = false;
		for (int add = 0; add < n; add++)
		{
			// 집합에 add가 없고(그래야 and 연산했을 때 0이 되므로)
			// add와 함께 있을 때 폭발하는 물질도 set에 없는 경우(0이 되는 경우)
			// 더 추가할 게 있다. 따라서 극대 안정 집합이 아니다. 이건.
			if ((set & (1 << add)) == 0 && (explodes[add] & set) == 0)
			{
				canExtend = true;
				break;
			}
		}
		// 더 이상 확장 못하면, 추가
		if (!canExtend)
			ret++;
	}
	return ret;
}

