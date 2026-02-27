#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    vector<int> count(tangerine.back()+1, 0);
    for(int i : tangerine){
        count[i]++;
    }
    sort(count.begin(), count.end(), greater<int>());
    for(int i : count){
        k -= i;
        answer++;
        if(k<=0) break;
    }
    return answer;
}