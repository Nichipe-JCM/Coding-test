#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> X_count(10);
    vector<int> Y_count(10);
    
    for(char x : X){
        X_count[x - '0']++;
    }
    
    for(char y : Y){
        Y_count[y - '0']++;
    }
    
    for(int i = 9; i >= 0; i--){
        if(X_count[i] == 0 || Y_count[i] == 0) continue;
        while(X_count[i] > 0 && Y_count[i] > 0){
            if(i == 0 && answer == ""){
                answer = "0";
                break;
            }
            answer.push_back((char)(i + '0'));
            X_count[i] -= 1;
            Y_count[i] -= 1;
        }
    }
    if(answer == "") return "-1";
    return answer;
}