#include<vector>
#include<queue>

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int row = maps.size();
    int column = maps[0].size();
    queue<pair<int, int>> mapqueue;
    vector<vector<bool>> isvisited(row, vector<bool>(column));
    mapqueue.push({0, 0});
    isvisited[0][0] = true;
    bool isgoalable = false;
    
    while(!mapqueue.empty())
    {
        int curx = mapqueue.front().first;
        int cury = mapqueue.front().second;
        if (curx == row - 1 && cury == column -1)
        {
            isgoalable = true;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int targetx = curx + dx[i];
            int targety = cury + dy[i];
            if (targetx < 0 || targetx >= row || targety < 0 || targety >= column) continue;
            if (maps[targetx][targety] == 0) continue;
            if (isvisited[targetx][targety]) continue;
            isvisited[targetx][targety] = true;
            mapqueue.push({targetx, targety});
            maps[targetx][targety] = maps[curx][cury] + 1;
        }
        mapqueue.pop();
    }
    if (isgoalable)
    {
        answer = maps[row - 1][column - 1];
        return answer;
    }
    else return -1;
}