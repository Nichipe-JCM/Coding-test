#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void dfs(const string& s, const int& cutcount, map<string, int>& menu , int index, string current)
{
    if (current.size() == cutcount)
    {
        menu[current]++;
        return;
    }
    if (index >= s.length()) return;
    
    dfs(s, cutcount, menu, index + 1, current + s[index]);
    dfs(s, cutcount, menu, index + 1, current);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(const int& cutcount : course)
    {
        map<string, int> menu;
        int maxcount = 0;
        for(const string& s : orders)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            dfs(temp, cutcount, menu, 0, "");
        }
        for(const auto& pair : menu)
        {
            if (pair.second > maxcount) maxcount = pair.second;
        }
        if (maxcount == 1) continue;
        for(const auto& pair : menu)
        {
            if (pair.second == maxcount) answer.push_back(pair.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}