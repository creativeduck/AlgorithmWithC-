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
    map<string, set<string>> reportMap; // ������ �� ������ �Ű��� ����� ����Ʈ ������ ��
    map<string, set<string>> reportedMap; // �Ű���� ������ �������� �Ű���ߴ��� ����Ʈ ������ ��

    // ���� �̸��� ���� �� �ʿ� �ֱ�
    for (string id : id_list)
    {
        reportMap[id] = {};
        reportedMap[id] = {};
    }
    // 1. map �������� ������ �װ� �Ű��� ��� ����Ʈ �����
    string from, to;
    for (string s : report)
    {
        vector<string> tmp = split(s);
        from = tmp[0]; to = tmp[1];
        // ������ �Ű��� ��� ����Ʈ�� �߰��ϱ�
        reportMap[from].insert(to);
        // �Ű���� ����� ���� �Ű��ߴ��� ����Ʈ �߰��ϱ�
        reportedMap[to].insert(from);
    }
    // 2. �Ű���� Ƚ�� ���鼭 �Ű�ó���ϱ�
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
�ϴ� ���� Ǯ����.
�����̶� ����, �ð��̳� ȿ������ ������� �ʾҴ�.
�ݺ��� ��ü�� ��ǻ� �� �� ���°ų� ����������,
�ð����⵵ ��ü�� O(n)�� �����Ѵ�.

�ٸ�, ���� ȿ������ ������ų ����� ã�� �ʹ�.

���� �� ���� ���� �̿��ϴ� ����� ����ߴ�.
�Ű��� ����� �Ű��� ����� set�� ���� �ʰ�,
�Ű���� ����� �ڽ��� �Ű��� ����� set�� ���� ���� ���´�.

�̰� �������� �� �Ű��� ����� �Ű��� set�� ��������,
�� ����� �Ű���� Ƚ���� ��������, �� ���� �Ӱ�ġ�� ������ �������� Ƚ���� �߰��ؼ� �̰� �� ���ؼ� ����迭�� �־���.

�̶� �Ű���� ��� ����Ʈ�� �ܼ��� �������� �ƴ϶� set���� ������ ������,
�Ű� �ߺ��� ��� �� ���� ���� �ϱ� �����̴�.

*/