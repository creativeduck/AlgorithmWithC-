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


*/