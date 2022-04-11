#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length() - k;
    int start = 0;
    for (int i = 0; i < number.length() - k; i++) // 각 자릿수 숫자 구하기
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

사실 내 풀이가 왜 틀렸는지는 기억나질 않지만, 접근방법은 비슷했다.

1) 먼저 숫자의 총 길이에서 k만큼 뺀 것까지 반복을 해서 탐색을 한다.
그러면 우리가 구하려고 하는 문자열의 길이만큼 탐색을 해서 원하는 숫자를 만들 수 있다.
즉, 총 len 번 탐색해서 len의 자리수에 해당하는 수를 각각 얻을 수 있다.

2) 위 반복문 내부에선, start부터 i+k까지 반복을 한다.
start는 맨 처음에 0으로 시작하며,
i+k가 의미하는 것은, 최대 i+k개까지 중에서 수를 선택할 수 있다는 것이다.
맨 마지막 시행에서 i는 length-1-k가 될 것이고, 여기에 k를 더한 length-1이 배열 끝이다.
즉, 각 자리수에서 고를 수 있는 범위 내에서 최대값을 구한ㄷ.
그리고 최댓값을 구하면 해당 자리수 다음으로 start값을 맞춰주고,
정답카운트 1을 추가한 후 다시 반복을 수행한다.

2중 반복문이므로 시간복잡도는 O(n^2)이다.

1. 정당성 증명
맨 앞자리가 가장 커야 결과적으로 가장 큰 수가 된다.
따라서 앞 자리를 가장 크게 만들어주는 경우가, 결론에서의 최적해로 이어진다.
*/