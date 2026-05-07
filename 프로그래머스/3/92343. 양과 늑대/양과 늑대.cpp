#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> seen;

void backtracking(const vector<int>& info, unordered_map<int, vector<int>>& tree, int& answer, int wolf, int sheep, int node, vector<int> candidates, vector<int> visited){
    int cursheep = info[node] == 0 ? sheep + 1 : sheep;
    int curwolf = info[node] == 1 ? wolf + 1 : wolf;
    if (curwolf >= cursheep) return;
    
    answer = cursheep > answer ? cursheep : answer;
    
    visited[node] = true;
    if(seen.count(visited)) return;
    seen.insert(visited);
    
    candidates.erase(remove(candidates.begin(), candidates.end(), node), candidates.end());
    for(int i : tree[node])
    {
        candidates.push_back(i);
    }
    
    for(int i : candidates)
    {
        backtracking(info, tree, answer, curwolf, cursheep, i, candidates, visited);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    unordered_map<int, vector<int>> tree;
    for(const vector<int>& v : edges)
    {
        tree[v[0]].push_back(v[1]);
    }
    vector<int> visited(info.size(), 0);
    
    backtracking(info, tree, answer, 0, 0, 0, {}, visited);
    
    return answer;
}