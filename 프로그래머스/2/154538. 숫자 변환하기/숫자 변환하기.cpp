#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int x, int y, int n)
{
    queue<pair<int, int>> q;
    q.push({x, 0});
    
    vector<bool> visited(1000001);
    visited[x] = true;
    
    while (!q.empty())
    {
        int currentVal = q.front().first;
        int currentCnt = q.front().second;
        q.pop();
        
        if (currentVal == y) return currentCnt;
        
        vector<int> next = {currentVal + n, currentVal * 2, currentVal * 3};
        
        for (int i : next)
        {
            if (i <= y && !visited[i])
            {
            visited[i] = true;
            q.push({i, currentCnt + 1});
            }
        }
        
    }
    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x, y, n);
}