#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
void recursion(int length, int y, int x, const vector<vector<int>>& arr, unordered_map<int, int>& countmap)
{
    int base = arr[y][x];
    if (length == 1)
    {
        countmap[base]++;
        return;
    }
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
        countmap[base]++;
        return;
    }
    else
    {
        int half = length / 2;
        recursion(half, y, x, arr, countmap);
        recursion(half, y + half, x, arr, countmap);
        recursion(half, y, x + half, arr, countmap);
        recursion(half, y + half, x + half, arr, countmap);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int length = arr.size();
    unordered_map<int, int> countmap;
    recursion(length, 0, 0, arr, countmap);
    answer = {countmap[0], countmap[1]};
    return answer;
}