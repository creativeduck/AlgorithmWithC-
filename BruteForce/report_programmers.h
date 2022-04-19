#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string str)
{
    vector<string> result;
    vector<char> cur;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || i == str.length() - 1)
        {
            string s = "";
            if (i == str.length() - 1)
                cur.push_back(str[i]);
            for (int j = 0; j < cur.size(); j++)
            {
                s += cur[j];
            }
            result.push_back(s);
            cur.clear();
        }
        else
            cur.push_back(str[i]);
    }
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int len = id_list.size();
    map<string, vector<string>> userMap; // 유저와 그 유저가 신고한 사람들 리스트 형식의 맵
    map<string, int> reportedMap;        // 각 유저별 신고당한 횟수
    map<string, int> reportedUser;       // 신고된 유저 리스트
    map<string, int> reportOverlap;      // 신고 중복 체크

    // 유저 이름들 먼저 각 맵에 넣기
    for (int i = 0; i < len; i++)
    {
        string user = id_list[i];
        reportedMap.insert({ user, 0 });
        vector<string> rp;
        userMap.insert({ user, rp });
    }
    // 1. map 형식으로 유저와 그가 신고한 사람 리스트 만들기
    string from, to;
    for (int i = 0; i < report.size(); i++)
    {
        vector<string> tmp = split(report[i]);
        from = tmp[0];
        to = tmp[1];
        // 유저가 신고한 사람 리스트에 추가해주기 
        vector<string> tmpReport = userMap[from];
        bool flag = true;
        for (int j = 0; j < tmpReport.size(); j++)
        {
            if (tmpReport[j] == to)
                flag = false;
        }
        if (flag)
        {
            userMap[from].push_back(to);
            // 신고당한 횟수 리스트 갱신하기
            reportedMap[to]++;
        }
    }
    // 2. 신고당한 횟수 보면서 신고처리하기
    for (int i = 0; i < len; i++)
    {
        string user = id_list[i];
        int reportNum = reportedMap[user];
        if (reportNum >= k)
            reportedUser.insert({ user, 1 });
        else
            reportedUser.insert({ user, 0 });
    }
    // 3. 각 유저별로 정지된 ID들 횟수 배열에 넣기
    for (int i = 0; i < len; i++)
    {
        string user = id_list[i];
        vector<string> reportList = userMap[user];
        int stoped = 0;
        // 이 유저가 신고한 사람들 중 정지된 횟수 반환하기
        for (int j = 0; j < reportList.size(); j++)
        {
            string thisguy = reportList[j];
            // 정지되었다면
            if (reportedUser[thisguy] == 1)
                stoped++;
        }
        answer.push_back(stoped);
    }


    return answer;
}

/*
일단 대충 풀었다.
대충이란 말은, 시간이나 효율성을 고려하지 않았다.
반복문 자체는 사실상 한 번 쓰는거나 마찬가지라서,
시간복잡도 자체는 O(n)에 수렴한다.

다만, 추후 효율성을 증가시킬 방법을 찾고 싶다.

*/