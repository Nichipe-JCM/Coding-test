#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void DFS(int start, int cut, int previous, int& count, const vector<vector<int>>& tree)
{
    count++;
    for (const int& i : tree[start])
    {
        if (i == cut || i == previous) continue;
        DFS(i, cut, start, count, tree);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    vector<vector<int>> tree(n + 1);
    
    for(const vector<int>& w : wires)
    {
        int a = w[0];
        int b = w[1];
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    for (const vector<int>& w : wires)
    {
        int count = 0;
        DFS(w[0], w[1], 0, count, tree);
        answer = min(answer, abs(count - (n - count)));
    }
        
    return answer;
}