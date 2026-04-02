#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minfatigue;

void mining(int depth, int currentfatigue, const vector<string>& minerals, vector<int>& picks){
    if (count(picks.begin(), picks.end(), 0) == picks.size() || depth >= minerals.size())
    {
        minfatigue = min(minfatigue, currentfatigue);
        return;
    }
    
    for(int i = 0; i < 3; i++)
    {
        if (picks[i] <= 0) continue;
        int fatigue = 0;
        for(int j = 0; j < 5; j++)
        {
            int targetindex = depth + j;
            if (targetindex >= minerals.size()) break;
            
            switch(i){
                case 0:
                    fatigue++;
                    break;
                case 1:
                    if (minerals[targetindex] == "diamond") fatigue += 5;
                    else fatigue++;
                    break;
                case 2:
                    if (minerals[targetindex] == "diamond") fatigue += 25;
                    else if (minerals[targetindex] == "iron") fatigue += 5;
                    else fatigue++;
                    break;
            }
        }
        picks[i]--;
        mining(depth + 5, currentfatigue + fatigue, minerals, picks);
        picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    minfatigue = 99999;
    mining(0, 0, minerals, picks);
    answer = minfatigue;
    return answer;
}