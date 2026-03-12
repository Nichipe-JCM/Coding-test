#include <string>
#include <vector>
#include <queue>

using namespace std;

void BFS(const int& n, const vector<vector<int>>& computers, queue<int>& q, vector<bool>& isvisited)
{
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && !isvisited[i])
            {
                q.push(i);
                isvisited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    vector<bool> isvisited(n);
    
    for(int i = 0; i < n; i++)
    {
        if (!isvisited[i])
        {
            answer++;
            q.push(i);
            isvisited[i] = true;
            BFS(n, computers, q, isvisited);
        }
    }
    return answer;
}