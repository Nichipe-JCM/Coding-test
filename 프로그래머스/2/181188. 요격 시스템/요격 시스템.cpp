#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b){
       return a[1] < b[1];
    });
    int current = targets[0][1];
    for(const vector<int>& vec : targets)
    {
        if (current <= vec[0])
        {
            current = vec[1];
            answer++;
        }
    }
    answer++;
    return answer;
}