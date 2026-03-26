#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

void recordpath(const vector<string>& grid,
         vector<vector<vector<bool>>>& isvisited,
         vector<int>& answer,
         int length, int currentway, int currentrow, int currentcolumn, 
         int& rowlength, int& columnlength){
    
    if (isvisited[currentrow][currentcolumn][currentway])
    {
        answer.push_back(length);
        return;
    }
    isvisited[currentrow][currentcolumn][currentway] = true;
    
    int nextway;
    switch(grid[currentrow][currentcolumn]){
        case 'S':
            nextway = currentway;
            break;
        case 'L':
            nextway = (currentway - 1 + 4) % 4;
            break;
        case 'R':
            nextway = (currentway + 1) % 4;
            break;
    };
    
    int nextrow = (currentrow + dy[nextway] + rowlength) % rowlength;
    int nextcol = (currentcolumn + dx[nextway] + columnlength) % columnlength;
    
    recordpath(grid, isvisited, answer, length + 1, nextway, nextrow, nextcol, rowlength, columnlength);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int row = grid.size();
    int column = grid[0].length();
    vector<vector<vector<bool>>> isvisited(row, vector<vector<bool>>(column, vector<bool>(4)));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if (isvisited[i][j][k]) continue;
                recordpath(grid, isvisited, answer, 0, k, i, j, row, column);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}