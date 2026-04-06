#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

int solution(vector<string> board) {
    vector<vector<int>> dist(board.size(), vector<int>(board[0].size(), -1));
    pair<int, int> R;
    pair<int, int> G;
    queue<pair<int, int>> q;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                R.first = i;
                R.second = j;
            }
            else if (board[i][j] == 'G')
            {
                G.first = i;
                G.second = j;
            }
        }
    }
    
    q.push(R);
    dist[R.first][R.second] = 0;
    
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top == G) return dist[top.first][top.second];
        int curx = top.first;
        int cury = top.second;
        
        for(int i = 0; i < 4; i++)
        {
            int nextx = curx;
            int nexty = cury;
            while (nextx + dx[i] >= 0 && nextx + dx[i] < board.size() &&
                   nexty + dy[i] >= 0 && nexty + dy[i] < board[0].size() &&
                   board[nextx + dx[i]][nexty + dy[i]] != 'D')
            {
                nextx += dx[i];
                nexty += dy[i];
            }
            if (dist[nextx][nexty] == -1)
            {
                q.push(pair<int, int>(nextx, nexty));
                dist[nextx][nexty] = dist[curx][cury] + 1;
            }
        }
    }
    return -1;
}