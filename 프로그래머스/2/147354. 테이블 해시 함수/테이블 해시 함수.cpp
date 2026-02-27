#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b){
        if (a[col - 1] != b[col - 1]) return a[col - 1] < b[col - 1];
        return a[0] > b[0];
    });
    
    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        int S_i = 0;
        for (const int& j : data[i])
        {
            S_i += j % (i + 1);
        }
        answer ^= S_i;
    }
    
    return answer;
}