#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rotate(int x1, int y1, int x2, int y2, vector<vector<int>>& map)
{
    int minimum = 10001;
    int xtop = x1, ytop = y1, xbot = x2, ybot = y2;
    int backup = map[xtop][ytop];
    minimum = min(minimum, backup);
    
    for (int i = xtop; i < xbot; i++)
    {
        map[i][ytop] = map[i + 1][ytop];
        minimum = min(minimum, map[i + 1][ytop]);
    }
    for (int i = ytop; i < ybot; i++)
    {
        map[xbot][i] = map[xbot][i + 1];
        minimum = min(minimum, map[xbot][i + 1]);
    }
    for (int i = xbot; i > xtop; i--)
    {
        map[i][ybot] = map[i - 1][ybot];
        minimum = min(minimum, map[i - 1][ybot]);
    }
    for (int i = ybot; i > ytop; i--)
    {
        map[xtop][i] = map[xtop][i - 1];
        minimum = min(minimum, map[xtop][i - 1]);
    }
    map[xtop][ytop + 1] = backup;
    return minimum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map(rows, vector<int>(columns));
    
    int count = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            map[i][j] = count;
            count++;
        }
    }
    for (const vector<int>& q : queries)
    {
        answer.push_back(rotate(q[0] - 1, q[1] - 1, q[2] - 1, q[3] - 1, map));
    }
    return answer;
}