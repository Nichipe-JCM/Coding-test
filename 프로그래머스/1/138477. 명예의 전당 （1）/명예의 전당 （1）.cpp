#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> vec;
    for(int s : score){
        if(vec.size() < k){
            vec.push_back(s);
            sort(vec.begin(), vec.end());
            answer.push_back(vec[0]);
        }
        else{
            vec.push_back(s);
            sort(vec.rbegin(), vec.rend());
            vec.pop_back();
            answer.push_back(vec[vec.size()-1]);
        }
    }
    return answer;
}