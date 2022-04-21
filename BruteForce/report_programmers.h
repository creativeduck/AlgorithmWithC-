#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

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
    map<string, set<string>> reportMap; // 유저와 그 유저가 신고한 사람들 리스트 형식의 맵
    map<string, set<string>> reportedMap; // 신고당한 유저가 누구에게 신고당했는지 리스트 형식의 맵

    // 유저 이름들 먼저 각 맵에 넣기
    for (string id : id_list)
    {
        reportMap[id] = {};
        reportedMap[id] = {};
    }
    // 1. map 형식으로 유저와 그가 신고한 사람 리스트 만들기
    string from, to;
    for (string s : report)
    {
        vector<string> tmp = split(s);
        from = tmp[0]; to = tmp[1];
        // 유저가 신고한 사람 리스트에 추가하기
        reportMap[from].insert(to);
        // 신고당한 사람도 누가 신고했는지 리스트 추가하기
        reportedMap[to].insert(from);
    }
    // 2. 신고당한 횟수 보면서 신고처리하기
    for (string id : id_list)
    {
        set<string> reportedSet = reportMap[id];
        int stopped = 0;
        for (string reported : reportedSet)
        {
            int reportNum = reportedMap[reported].size();
            if (reportNum >= k)
                stopped++;
        }
        answer.push_back(stopped);
    }
    return answer;
}
/*
일단 대충 풀었다.
대충이란 말은, 시간이나 효율성을 고려하지 않았다.
반복문 자체는 사실상 한 번 쓰는거나 마찬가지라서,
시간복잡도 자체는 O(n)에 수렴한다.

다만, 추후 효율성을 증가시킬 방법을 찾고 싶다.

이후 두 개의 맵을 이용하는 방식을 사용했다.
신고한 사람이 신고한 사람들 set를 갖는 맵과,
신고당한 사람이 자신을 신고한 사람들 set를 갖는 맵을 갖는다.

이걸 바탕으로 각 신고한 사람이 신고한 set을 바탕으로,
그 사람이 신고당한 횟수를 가져오고, 이 값이 임계치를 넘으면 정지당한 횟수를 추가해서 이걸 다 합해서 정답배열에 넣었다.

이때 신고당한 사람 리스트를 단순히 정수형이 아니라 set으로 구현한 이유는,
신고를 중복한 경우 한 번만 들어가야 하기 때문이다.

*/