#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(const vector<int>& v : puddles)
    {
        dp[v[0] - 1][v[1] - 1] = -1;
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1 || (i == 0 && j == 0)) continue;
            int fromleft = (i - 1 < 0 || dp[i - 1][j] == -1) ? 0 : dp[i - 1][j];
            int fromup = (j - 1 < 0 || dp[i][j - 1] == -1) ? 0 : dp[i][j - 1];
            dp[i][j] = (fromleft + fromup) % 1000000007;
        }
    }
    answer = dp[m - 1][n - 1];
    return answer;
}