#include <vector>

using namespace std;
int student[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 0; i < lost.size(); i++)
    {
        int idx = lost[i];
        student[idx]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        int idx = reserve[i];
        student[idx]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (student[i] == -1)
        {
            if (student[i - 1] == 1)
                student[i - 1] = student[i] = 0;
            else if (student[i + 1] == 1)
                student[i] = student[i + 1] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (student[i] >= 0)
            answer++;
    }
    return answer;
}

