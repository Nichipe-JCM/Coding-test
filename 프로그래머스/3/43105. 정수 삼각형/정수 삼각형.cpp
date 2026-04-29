#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp = triangle;
    for(int i = 1; i < dp.size(); i++)
    {
        for(int j = 0; j < dp[i].size(); j++)
        {
            if (j == 0)
            {
                dp[i][j] += dp[i - 1][j];
                continue;
            }
            else if (j == dp[i].size() - 1)
            {
                dp[i][j] += dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    answer = *max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
    return answer;
}