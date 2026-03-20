#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    for(int i = 0; i < 26; i++)
    {
        string s(1, 'A' + i);
        dict[s] = i + 1;
    }
    int nextindex = 27;
    
    for(int i = 0; i < msg.length();)
    {
        int checklength = 1;
        int foundlength = 1;
        while(true)
        {
            if (i + checklength > msg.length()) break;
            string checksubstr = msg.substr(i, checklength);
            auto it = dict.find(checksubstr);
            if (it == dict.end())
            {
                dict[checksubstr] = nextindex;
                nextindex++;
                break;
            }
            foundlength = checklength;
            checklength++;
        }
        string foundstr = msg.substr(i, foundlength);
        answer.push_back(dict[foundstr]);
        i += foundlength;
    }
    return answer;
}