#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> vec;
    if(m > score.size()) return 0;
    sort(score.rbegin(), score.rend());
    for(int s : score){
        vec.push_back(s);
        if(vec.size() == m){
            answer+=vec[m-1]*m;
            vec.clear();
        }
    }
    return answer;
}