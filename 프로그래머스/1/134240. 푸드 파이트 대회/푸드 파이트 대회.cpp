#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i = 1; i < food.size(); i++){
        if(food[i] < 2) continue;
        if(food[i] % 2 == 1) food[i] -= 1;
        for(int j = 0; j < food[i]/2; j++){
            answer += to_string(i);
        }
    }
    answer+='0';
    for(int k = food.size()-1; k > 0; k--){
        for(int l = 0; l < food[k]/2; l++){
            answer += to_string(k);
        }
    }
    return answer;
}