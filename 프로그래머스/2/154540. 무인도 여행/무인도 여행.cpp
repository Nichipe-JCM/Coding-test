#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int row, int column, vector<vector<bool>>& isvisited, vector<string>& maps)
{
    int sum = 0;
    queue<pair<int, int>> search;
    search.push({row, column});
    sum += maps[row][column] - '0';
    isvisited[row][column] = true;
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};
    
    while (!search.empty())
    {
        int currow = search.front().first;
        int curcol = search.front().second;
        for(int i = 0; i < 4; i++)
        {
            int newcol = curcol + dcol[i];
            int newrow = currow + drow[i];
            if (newrow < 0 || newrow >= maps.size() || newcol < 0 || newcol >= maps[0].length()) continue; 
            if (isvisited[newrow][newcol] || maps[newrow][newcol] == 'X') continue;
            isvisited[newrow][newcol] = true;
            sum += maps[newrow][newcol] - '0';
            search.push({newrow, newcol});
        }
        search.pop();
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int row = maps.size();
    int column = maps[0].length();    
    vector<vector<bool>> isvisited(row, vector<bool>(column, false));
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if (maps[i][j] != 'X' && !isvisited[i][j]) answer.push_back(BFS(i, j, isvisited, maps));
        }
    }
    if (answer.empty()) return vector<int>{-1};
    sort(answer.begin(), answer.end());
    return answer;
}