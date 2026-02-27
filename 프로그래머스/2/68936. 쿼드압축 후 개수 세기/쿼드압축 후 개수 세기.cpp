#include <string>
#include <vector>

using namespace std;
void recursion(int length, int y, int x, const vector<vector<int>>& arr, vector<int>& answer)
{
    int base = arr[y][x];
    bool iscompable = true;
    for (int i = y; i < y + length; i++)
    {
        for (int j = x; j < x + length; j++)
        {
            if (arr[i][j] != base)
            {
                iscompable = false;
                break;
            }
        }
        if (!iscompable) break;
    }
    if (iscompable)
    {
        answer[base]++;
        return;
    }
    else
    {
        int half = length / 2;
        recursion(half, y, x, arr, answer);
        recursion(half, y + half, x, arr, answer);
        recursion(half, y, x + half, arr, answer);
        recursion(half, y + half, x + half, arr, answer);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int length = arr.size();
    recursion(length, 0, 0, arr, answer);
    return answer;
}