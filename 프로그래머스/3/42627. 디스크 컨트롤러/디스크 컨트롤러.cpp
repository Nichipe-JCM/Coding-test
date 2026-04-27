#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(const vector<int>& a, const vector<int>& b){
        if (a[1] != b[1]) return a[1] > b[1];
        if (a[0] != b[0]) return a[0] > b[0];
        return false;
    };
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    sort(jobs.begin(), jobs.end());
    
    int currenttime = 0;
    int idx = 0;
    int finished = 0;
    while (finished < jobs.size())
    {
        if (idx < jobs.size() && jobs[idx][0] <= currenttime)
        {
            pq.push(jobs[idx]);
            idx++;
            continue;
        }
        if (!pq.empty())
        {
            vector<int> current = pq.top();
            pq.pop();
            currenttime += current[1];
            answer += currenttime - current[0];
            finished++;
        }
        else currenttime = jobs[idx][0];
    }
    answer /= jobs.size();
    return answer;
}