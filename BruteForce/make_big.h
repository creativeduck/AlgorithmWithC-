#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length() - k;
    int start = 0;
    for (int i = 0; i < number.length() - k; i++) // �� �ڸ��� ���� ���ϱ�
    {
        int maxIdx = start;
        int maxVal = (int)number[start] - '0';
        for (int j = start; j <= i + k; j++)
        {
            int num = (int)number[j] - '0';
            if (maxVal < num)
            {
                maxVal = num;
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += number[maxIdx];
    }
    return answer;
}

/*

��� �� Ǯ�̰� �� Ʋ�ȴ����� ��ﳪ�� ������, ���ٹ���� ����ߴ�.

1) ���� ������ �� ���̿��� k��ŭ �� �ͱ��� �ݺ��� �ؼ� Ž���� �Ѵ�.
�׷��� �츮�� ���Ϸ��� �ϴ� ���ڿ��� ���̸�ŭ Ž���� �ؼ� ���ϴ� ���ڸ� ���� �� �ִ�.
��, �� len �� Ž���ؼ� len�� �ڸ����� �ش��ϴ� ���� ���� ���� �� �ִ�.

2) �� �ݺ��� ���ο���, start���� i+k���� �ݺ��� �Ѵ�.
start�� �� ó���� 0���� �����ϸ�,
i+k�� �ǹ��ϴ� ����, �ִ� i+k������ �߿��� ���� ������ �� �ִٴ� ���̴�.
�� ������ ���࿡�� i�� length-1-k�� �� ���̰�, ���⿡ k�� ���� length-1�� �迭 ���̴�.
��, �� �ڸ������� �� �� �ִ� ���� ������ �ִ밪�� ���Ѥ�.
�׸��� �ִ��� ���ϸ� �ش� �ڸ��� �������� start���� �����ְ�,
����ī��Ʈ 1�� �߰��� �� �ٽ� �ݺ��� �����Ѵ�.

2�� �ݺ����̹Ƿ� �ð����⵵�� O(n^2)�̴�.

1. ���缺 ����
�� ���ڸ��� ���� Ŀ�� ��������� ���� ū ���� �ȴ�.
���� �� �ڸ��� ���� ũ�� ������ִ� ��찡, ��п����� �����ط� �̾�����.
*/