#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while(!priorities.empty())
    {
        int comp = priorities[0];
        bool isQueued = false;
        for (int i = 1; i < priorities.size(); i++)
        {
            if (comp < priorities[i])
            {
                priorities.push_back(comp);
                priorities.erase(priorities.begin());
                isQueued = true;
                location--;
                if (location < 0) location = priorities.size() - 1;
                break;
            }
        }
        if (!isQueued)
        {
            priorities.erase(priorities.begin());
            answer++;
            location--;
            if (location < 0) break;
        }
    }
    return answer;
}