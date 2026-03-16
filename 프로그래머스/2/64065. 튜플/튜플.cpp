#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> svector;
    int vectorindex = 0;
    string temp = "";
    bool isopen = false;
    for(int i = 1; i < s.length() - 1; i++)
    {
        if(s[i] == '{')
        {
            svector.push_back(vector<int>());
            isopen = true;
        }
        else if(s[i] == ',' && isopen)
        {
            svector[vectorindex].push_back(stoi(temp));
            temp = "";
        }
        else if(s[i] == '}')
        {
            svector[vectorindex].push_back(stoi(temp));
            temp = "";
            isopen = false;
            vectorindex++;
        }
        else if (isopen) temp += s[i];
    }
    
    sort(svector.begin(), svector.end(), [](const vector<int>& a, const vector<int>& b){
        return a.size() < b.size();
    });
    
    unordered_set<int> us;
    for(const vector<int>& v : svector)
    {
        for(int i : v)
        {
            if (us.find(i) == us.end())
            {
                answer.push_back(i);
                us.insert(i);
                break;
            }
        }
    }
    
    return answer;
}