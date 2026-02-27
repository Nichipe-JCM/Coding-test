#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int x = 0, y = 0;
    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };
    int dir = 0;
    for (int i = 0; i < n * n; i++) {
        answer[y][x] = i + 1;
        int next_y = y + dy[dir];
        int next_x = x + dx[dir];
        bool oorCheck = (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n);
        if (oorCheck || answer[next_y][next_x] != 0) {
            dir = (dir + 1) % 4;
            next_y = y + dy[dir];
            next_x = x + dx[dir];
        }
        x = next_x;
        y = next_y;
    }
    return answer;
}