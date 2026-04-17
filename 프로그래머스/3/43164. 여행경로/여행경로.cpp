#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void DFS(int depth, int maxdepth, const string& nextdest, vector<string>& visitedlist, map<string, vector<string>>& dest, map<string, vector<bool>>& isused, vector<string>& answer, bool& issearchend){
    if (issearchend) return;
    if (depth == maxdepth)
    {
        answer = visitedlist;
        issearchend = true;
        return;
    }
    
    for(int i = 0; i < dest[nextdest].size(); i++)
    {
        if (isused[nextdest][i]) continue;
        isused[nextdest][i] = true;
        visitedlist.push_back(dest[nextdest][i]);
        DFS(depth + 1, maxdepth, dest[nextdest][i], visitedlist, dest, isused, answer, issearchend);
        visitedlist.pop_back();
        isused[nextdest][i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<string>> dest;
    map<string, vector<bool>> isused;
    for(const vector<string>& v : tickets) dest[v[0]].push_back(v[1]);
    for(auto& pair : dest)
    {
        isused[pair.first].resize(pair.second.size(), false);
        sort(pair.second.begin(), pair.second.end());
    }
    bool issearchend = false;
    vector<string> visitedlist = {"ICN"};
    DFS(0, tickets.size(), "ICN", visitedlist, dest, isused, answer, issearchend);
    return answer;
}