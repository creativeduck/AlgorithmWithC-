#include <vector>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    // 처음에 모든 알파벳 변환 값들 구하기
    for (int i = 0; i < name.length(); i++)
    {
        int num = min((int)name[i] - 'A', (int)'Z' - name[i] + 1);
        answer += num;
    }

    int fst = 0, aTmp = 0;
    int indirect = 100000000;
    bool faceA = false;
    // 정석
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
    // 간접
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
        // 처음부터 front 까지 step이랑 바꾸기 구하기
        for (int i = 1; i <= front; i++)
            frontStep++;
        // 처음부터 back까지 step이랑 바꾸기 구하기
        for (int i = back; i < name.length(); i++)
            backStep++;
        int tmp = min(frontStep, backStep) + backStep + frontStep;
        indirect = min(indirect, tmp);
    }
    answer += min(fst, indirect);
    return answer;
}


/*
도저히 못 풀겠어서 일단 반례를 찾았다.
그런데 내가 생각했던 로직 자체는 정답과 가까웠다.
따라서 로직을 수정하였고,
일직선으로 가는 정석대로의 횟수를 우선 구하고,

뒤로 돌아간 다음 다시 돌아와서 앞으로 가는 횟수를 구했다.
그리고 그 두 경로 중 짧은 것을 한 번 더 더하면 최솟값이 나오는 로직을 사용했다.

간접 경로를 구하는 방법은 다음과 같다.
1) 먼저 back에 해당하는, 즉 뒤로 가는 경로에서 시작 지점을 구한다.
배열의 길이-1부터 1까지 뒤로 갔다가 돌아갈 수 있으므로, 그렇게 범위를 설정했다.

2) back에서부터 0까지 앞으로 이동하면서 A가 아닌 지점을 찾는다.
그리고 이 지점을 front 라 한다.
즉, A는 정석으로 갈 때, 이 지점까지 가야한다.

3) 뒤로 가는 경로와 앞으로 가는 경로를 구한다.
그리고 각 경로에서 우선 알파벳 변환 횟수를 더한 후,
각 경로 중 더 짧은 경로를 한 번 더 더해준다. 되돌아와야 하므로.

이 값들 중 최솟값을 답으로 하면 된다.

이때, 각 알파벳 변환은 A부터 시작하는 것과, Z에서 시작하는 것 중 최솟값으로 하며,
Z로 구할 땐 한 번의 변환이 더 필요하므로, 1을 더한다.


각 반복문은 중첩은 2중이지만 반복문이 많기는 하다.

1. 정당성 증명
뒤로 가는 것과 앞으로 가는 것이 경우의 수이다.
이때 둘 중 한 경로로는 다시 돌아와야 하므로, 최솟값을 더하는 것이 최솟 경우의 수가 된다.

*/