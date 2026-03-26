#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int row = grid.size();
    int column = grid[0].length();
    vector<vector<vector<bool>>> isvisited(row, vector<vector<bool>>(column, vector<bool>(4)));
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < column; c++)
        {
            for(int w = 0; w < 4; w++)
            {
                if (isvisited[r][c][w]) continue;
                int length = 0;
                int currentrow = r;
                int currentcol = c;
                int currentway = w;
                while(true)
                {
                    if (isvisited[currentrow][currentcol][currentway])
                    {
                        answer.push_back(length);
                        break;
                    }
                    isvisited[currentrow][currentcol][currentway] = true;
                    
                    switch(grid[currentrow][currentcol]){
                        case 'S':
                            currentway = currentway;
                            break;
                        case 'L':
                            currentway = (currentway - 1 + 4) % 4;
                            break;
                        case 'R':
                            currentway = (currentway + 1) % 4;
                            break;
                    };
    
                    currentrow = (currentrow + dy[currentway] + row) % row;
                    currentcol = (currentcol + dx[currentway] + column) % column;
                    length++;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}