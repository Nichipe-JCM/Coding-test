#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            int prevmax = -1;
            
            for(int k = 0; k < land[i - 1].size(); k++)
            {
                if (k == j) continue;
                prevmax = max(prevmax, land[i - 1][k]);
            }
            
            land[i][j] = land[i][j] + prevmax;
        }
    }
    
    answer = *max_element(land.back().begin(), land.back().end());
    return answer;
}