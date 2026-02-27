#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> DtC;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int days = 0;
        while(true)
        {
            progresses[i] += speeds[i];
            days++;
            if (progresses[i] >= 100) break;
        }
        DtC.push_back(days);
    }
    
    for(int i = 0; i < DtC.size(); i++)
    {
        int count = 1;
        int addindex = 1;
        while(true)
        {
            if (i + addindex == DtC.size()) break;
            if (DtC[i] >= DtC[i + addindex])
            {
                count++;
                addindex++;
            }
            else break;
        }
        i += addindex - 1;
        answer.push_back(count);
    }
    return answer;
}