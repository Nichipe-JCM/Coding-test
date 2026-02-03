#include <string>
#include <vector>

using namespace std;

int max_count = 0;
vector<bool> visited(8, false);

void dfs(int k, int count, vector<vector<int>> dungeons) {
    if (count > max_count) max_count = count;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], count + 1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    dfs(k, 0, dungeons);
    answer = max_count;
    return answer;
}