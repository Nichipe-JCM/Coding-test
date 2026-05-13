#include <string>
#include <vector>

using namespace std;

void floydwarshall(int n, vector<vector<int>>& wingraph){
    for(int k = 1; k <= n; k++) //경유지
    {
        for(int i = 1; i <= n; i++) //출발지
        {
            for(int j = 1; j <= n; j++) //도착지
            {
                if(wingraph[i][k] && wingraph[k][j]) wingraph[i][j] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> wingraph(n + 1, vector<int>(n + 1, 0));
    for(const vector<int>& vec : results) wingraph[vec[0]][vec[1]] = 1;
    
    floydwarshall(n, wingraph);
    
    for(int i = 1; i <= n; i++)
    {
        int wincount = 0;
        for(int j = 1; j <= n; j++)
        {
            if (wingraph[i][j]) wincount++;
            if (wingraph[j][i]) wincount++;
        }
        if(wincount == n - 1) answer++;
    }
    return answer;
}