#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    for(vector<int> vec : sizes){
        int big = max(vec[0], vec[1]);
        int small = min(vec[0], vec[1]);
        if(big > w) w = big;
        if(small > h) h = small;
    }
    answer = w*h;
    return answer;
}