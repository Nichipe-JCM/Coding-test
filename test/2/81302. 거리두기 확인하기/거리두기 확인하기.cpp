#include <string>
#include <vector>

using namespace std;

vector<int> drow = {-1, 1, 0, 0};
vector<int> dcol = {0, 0, -1, 1};

void DFS(const vector<vector<string>>& places, vector<vector<bool>>& isvisited, int depth, int row, int col, bool& isnotok, int& roomnum)
{
    if (depth >= 2 || isnotok) return;

    for (int i = 0; i < 4; i++)
    {
        int newrow = row + drow[i];
        int newcol = col + dcol[i];
        if (newrow < 0 || newrow >= places[roomnum].size() || newcol < 0 || newcol >= places[roomnum][0].size()) continue;
        if (isvisited[newrow][newcol]) continue;
        if (places[roomnum][newrow][newcol] == 'X') continue;
        if (places[roomnum][newrow][newcol] == 'P')
        {
            isnotok = true;
            return;
        }
        isvisited[newrow][newcol] = true;
        DFS(places, isvisited, depth + 1, newrow, newcol, isnotok, roomnum);
    }
}

bool isroomok(const vector<vector<string>>& places, int& roomnum){
    for (int i = 0; i < places[roomnum].size(); i++)
    {
        for (int j = 0; j < places[roomnum][i].length(); j++)
        {
            if (places[roomnum][i][j] == 'X' || places[roomnum][i][j] == 'O') continue;
            bool isnotok = false;
            vector<vector<bool>> isvisited(places[roomnum].size(), vector<bool>(places[roomnum][0].length(), false));
            isvisited[i][j] = true;
            DFS(places, isvisited, 0, i, j, isnotok, roomnum);
            if (isnotok) return false;            
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < places.size(); i++)
    {
        bool check = isroomok(places, i);
        if (check) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}