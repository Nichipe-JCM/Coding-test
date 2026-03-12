#include <string>
#include <vector>
#include <queue>

using namespace std;

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
            while(!q.empty())
            {
                int current = q.front();
                q.pop();
                for(int j = 0; j < n; j++)
                {
                    if (computers[current][j] == 1 && !isvisited[j])
                    {
                        q.push(j);
                        isvisited[j] = true;
                    }
                }
            }
        }
    }
    return answer;
}