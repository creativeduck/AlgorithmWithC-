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
    map<string, vector<string>> userMap; // ������ �� ������ �Ű��� ����� ����Ʈ ������ ��
    map<string, int> reportedMap;        // �� ������ �Ű���� Ƚ��
    map<string, int> reportedUser;       // �Ű�� ���� ����Ʈ
    map<string, int> reportOverlap;      // �Ű� �ߺ� üũ

    // ���� �̸��� ���� �� �ʿ� �ֱ�
    for (int i = 0; i < len; i++)
    {
        string user = id_list[i];
        reportedMap.insert({ user, 0 });
        vector<string> rp;
        userMap.insert({ user, rp });
    }
    // 1. map �������� ������ �װ� �Ű��� ��� ����Ʈ �����
    string from, to;
    for (int i = 0; i < report.size(); i++)
    {
        vector<string> tmp = split(report[i]);
        from = tmp[0];
        to = tmp[1];
        // ������ �Ű��� ��� ����Ʈ�� �߰����ֱ� 
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
            // �Ű���� Ƚ�� ����Ʈ �����ϱ�
            reportedMap[to]++;
        }
    }
    // 2. �Ű���� Ƚ�� ���鼭 �Ű�ó���ϱ�
    for (int i = 0; i < len; i++)
    {
        string user = id_list[i];
        int reportNum = reportedMap[user];
        if (reportNum >= k)
            reportedUser.insert({ user, 1 });
        else
            reportedUser.insert({ user, 0 });
    }
    // 3. �� �������� ������ ID�� Ƚ�� �迭�� �ֱ�
    for (int i = 0; i < len; i++)
    {
        string user = id_list[i];
        vector<string> reportList = userMap[user];
        int stoped = 0;
        // �� ������ �Ű��� ����� �� ������ Ƚ�� ��ȯ�ϱ�
        for (int j = 0; j < reportList.size(); j++)
        {
            string thisguy = reportList[j];
            // �����Ǿ��ٸ�
            if (reportedUser[thisguy] == 1)
                stoped++;
        }
        answer.push_back(stoped);
    }


    return answer;
}

/*
�ϴ� ���� Ǯ����.
�����̶� ����, �ð��̳� ȿ������ ������� �ʾҴ�.
�ݺ��� ��ü�� ��ǻ� �� �� ���°ų� ����������,
�ð����⵵ ��ü�� O(n)�� �����Ѵ�.

�ٸ�, ���� ȿ������ ������ų ����� ã�� �ʹ�.

*/