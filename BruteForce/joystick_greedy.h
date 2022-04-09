#include <vector>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    // ó���� ��� ���ĺ� ��ȯ ���� ���ϱ�
    for (int i = 0; i < name.length(); i++)
    {
        int num = min((int)name[i] - 'A', (int)'Z' - name[i] + 1);
        answer += num;
    }

    int fst = 0, aTmp = 0;
    int indirect = 100000000;
    bool faceA = false;
    // ����
    for (int i = 1; i < name.length(); i++)
    {
        if (name[i] == 'A')
        {
            faceA = true;
            aTmp++;
        }
        else
        {
            faceA = false;
            fst += aTmp;
            aTmp = 0;
        }
        if (!faceA)
            fst += 1;
    }
    // ����
    for (int i = name.length() - 1; i > 0; i--)
    {
        if (name[i] == 'A')
            continue;
        int back = i;
        for (back; back > 0; back--)
        {
            if (name[back] != 'A')
                continue;
            else
                break;
        }
        back += 1;
        int k;
        for (k = back - 1; k > 0; k--)
        {
            if (name[k] == 'A')
                continue;
            else
                break;
        }
        int front = k;
        int frontStep = 0, backStep = 0;
        // ó������ front ���� step�̶� �ٲٱ� ���ϱ�
        for (int i = 1; i <= front; i++)
            frontStep++;
        // ó������ back���� step�̶� �ٲٱ� ���ϱ�
        for (int i = back; i < name.length(); i++)
            backStep++;
        int tmp = min(frontStep, backStep) + backStep + frontStep;
        indirect = min(indirect, tmp);
    }
    answer += min(fst, indirect);
    return answer;
}


/*
������ �� Ǯ�ھ �ϴ� �ݷʸ� ã�Ҵ�.
�׷��� ���� �����ߴ� ���� ��ü�� ����� �������.
���� ������ �����Ͽ���,
���������� ���� ��������� Ƚ���� �켱 ���ϰ�,

�ڷ� ���ư� ���� �ٽ� ���ƿͼ� ������ ���� Ƚ���� ���ߴ�.
�׸��� �� �� ��� �� ª�� ���� �� �� �� ���ϸ� �ּڰ��� ������ ������ ����ߴ�.

���� ��θ� ���ϴ� ����� ������ ����.
1) ���� back�� �ش��ϴ�, �� �ڷ� ���� ��ο��� ���� ������ ���Ѵ�.
�迭�� ����-1���� 1���� �ڷ� ���ٰ� ���ư� �� �����Ƿ�, �׷��� ������ �����ߴ�.

2) back�������� 0���� ������ �̵��ϸ鼭 A�� �ƴ� ������ ã�´�.
�׸��� �� ������ front �� �Ѵ�.
��, A�� �������� �� ��, �� �������� �����Ѵ�.

3) �ڷ� ���� ��ο� ������ ���� ��θ� ���Ѵ�.
�׸��� �� ��ο��� �켱 ���ĺ� ��ȯ Ƚ���� ���� ��,
�� ��� �� �� ª�� ��θ� �� �� �� �����ش�. �ǵ��ƿ;� �ϹǷ�.

�� ���� �� �ּڰ��� ������ �ϸ� �ȴ�.

�̶�, �� ���ĺ� ��ȯ�� A���� �����ϴ� �Ͱ�, Z���� �����ϴ� �� �� �ּڰ����� �ϸ�,
Z�� ���� �� �� ���� ��ȯ�� �� �ʿ��ϹǷ�, 1�� ���Ѵ�.


�� �ݺ����� ��ø�� 2�������� �ݺ����� ����� �ϴ�.

1. ���缺 ����
�ڷ� ���� �Ͱ� ������ ���� ���� ����� ���̴�.
�̶� �� �� �� ��ηδ� �ٽ� ���ƿ;� �ϹǷ�, �ּڰ��� ���ϴ� ���� �ּ� ����� ���� �ȴ�.

*/