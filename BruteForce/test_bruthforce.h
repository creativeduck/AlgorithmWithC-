#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr[4] = { 0, 0, 0, 0 };
    int fst[5] = { 1, 2, 3, 4, 5 };
    int sec[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int trd[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    for (int i = 0; i < answers.size(); i++)
    {
        if (fst[i % 5] == answers[i])
            arr[1]++;
        if (sec[i % 8] == answers[i])
            arr[2]++;
        if (trd[i % 10] == answers[i])
            arr[3]++;
    }
    int maxVal = arr[1];
    for (int i = 2; i < 4; i++)
    {
        if (maxVal < arr[i])
            maxVal = arr[i];
    }
    for (int i = 1; i < 4; i++)
    {
        if (maxVal == arr[i])
            answer.push_back(i);
    }
    return answer;
}

/*
엄청 단순하게 풀었다.
배열의 인덱스를 %로 해서 정답 횟수를 구하고,
이후 최대 크기를 구한 다음,
그 크기에 맞는 것들은 순서대로 배열에 더했다.
최종 시간복잡도는 for 문 1중 반복이므로, O(n)이다.
*/