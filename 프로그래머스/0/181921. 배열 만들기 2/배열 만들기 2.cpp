#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i = l; i <= r; i++){
        string num = to_string(i);
        bool check = true;
        for(int j = 0; j < num.length() ; j++){
            if (num[j] != '0' && num[j] != '5'){
                check = false;
                break;
            }
        }
        if(check){
            answer.push_back(i);
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    return answer;
}