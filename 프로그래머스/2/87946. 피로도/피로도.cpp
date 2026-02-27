#include <string>
#include <vector>

using namespace std;

void dfs(int k, int count, const vector<vector<int>>& dungeons, vector<bool>& visited, int& answer) {
    if (count > answer) answer = count;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], count + 1, dungeons, visited, answer);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    dfs(k, 0, dungeons, visited, answer);
    return answer;
}