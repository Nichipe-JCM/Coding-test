#include <string>
#include <vector>

using namespace std;

int maxdiff = 0;
vector<int> bestscore = {-1};

void DFS(int n, const vector<int>& info, vector<int> currentscore, int depth){
    if (depth == 11 || n == 0)
    {
        currentscore[10] += n;
        int lionscore = 0;
        int apeachscore = 0;
        
        for(int i = 0; i < 11; i++)
        {
            if (currentscore[i] > info[i]) lionscore += 10 - i;
            else if (currentscore[i] <= info[i] && info[i] > 0) apeachscore += 10 - i;
        }
        
        int diff = lionscore - apeachscore;
        
        if (diff > 0 && diff > maxdiff)
        {
            maxdiff = diff;
            bestscore = currentscore;
        }
        else if (diff > 0 && diff == maxdiff)
        {
            for(int i = 10; i >= 0; i--)
            {
                if (currentscore[i] > bestscore[i])
                {
                    bestscore = currentscore;
                    break;
                }
                else if (currentscore[i] < bestscore[i]) break;
            }
        }
        
        return;
    }
    
    DFS(n, info, currentscore, depth + 1);
    
    if (n > info[depth])
    {
        int nextn = n - (info[depth] + 1);
        currentscore[depth] = info[depth] + 1;
        DFS(nextn, info, currentscore, depth + 1);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    DFS(n, info, vector<int>(11, 0), 0);
    
    answer = bestscore;
    
    return answer;
}