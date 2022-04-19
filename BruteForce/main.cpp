#include "safe_2468.h"
#include <vector>
using namespace std;

vector<string> split(string str)
{
	vector<string> result;
	vector<char> cur;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' || i == str.length()-1)
		{
			string s = "";
			if (i == str.length()-1)
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

int main()
{
	//solution();
	string tmp = "asdf asdf";
	int idx = 0;
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == ' ')
			idx = i;
	}
	cout << idx << '\n';
	
	vector<string> answer = split(tmp);
	for(int i=0; i<answer.size(); i++)
		cout << answer[i] << '\n';



	return 0;
}