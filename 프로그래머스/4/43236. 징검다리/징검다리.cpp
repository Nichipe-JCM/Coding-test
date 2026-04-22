#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int left = 1;
    int right = distance;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int point = 0;
        int count = 0;
        for(int i = 0; i < rocks.size(); i++)
        {
            int distbetween = rocks[i] - point;
            if (distbetween < mid) count++;
            else point = rocks[i];
        }
        if (distance - point < mid) count++;
        
        if (count <= n)
        {
            answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return answer;
}