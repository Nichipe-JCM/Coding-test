#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int column, int row, vector<vector<bool>>& isvisited, vector<string>& maps)
{
    int sum = 0;
    queue<pair<int, int>> search;
    search.push({column, row});
    sum += maps[column][row] - '0';
    isvisited[column][row] = true;
    vector<int> dcol = {-1, 1, 0, 0};
    vector<int> drow = {0, 0, -1, 1};
    
    while (!search.empty())
    {
        int curcol = search.front().first;
        int currow = search.front().second;
        for(int i = 0; i < 4; i++)
        {
            int newcol = curcol + dcol[i];
            int newrow = currow + drow[i];
            if (newcol < 0 || newcol >= maps.size() || newrow < 0 || newrow >= maps[0].length()) continue; 
            if (isvisited[newcol][newrow] || maps[newcol][newrow] == 'X') continue;
            isvisited[newcol][newrow] = true;
            sum += maps[newcol][newrow] - '0';
            search.push({newcol, newrow});
        }
        search.pop();
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int column = maps.size();
    int row = maps[0].length();    
    vector<vector<bool>> isvisited(column, vector<bool>(row, false));
    
    for(int i = 0; i < column; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if (maps[i][j] != 'X' && !isvisited[i][j]) answer.push_back(BFS(i, j, isvisited, maps));
        }
    }
    if (answer.empty()) return vector<int>{-1};
    sort(answer.begin(), answer.end());
    return answer;
}