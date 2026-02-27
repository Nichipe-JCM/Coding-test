#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min = 0;
    int max = 0;
    for(int w : lottos){
        if(w == 0){
            max++;
            continue;
        }
        auto it = find(win_nums.begin(), win_nums.end(), w);
        if (it != win_nums.end()){
            min++;
            max++;
        }
    }
    vector<int> win = {6,6,5,4,3,2,1};
    answer.push_back(win[max]);
    answer.push_back(win[min]);
    return answer;
}