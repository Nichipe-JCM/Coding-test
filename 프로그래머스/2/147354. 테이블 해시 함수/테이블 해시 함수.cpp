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
    
    vector<int> S_i(data.size(), 0);
    for(int i = 0; i < data.size(); i++)
    {
        for (const int& j : data[i])
        {
            S_i[i] += j % (i + 1);
        }
    }
    
    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        answer ^= S_i[i];
    }
    
    return answer;
}