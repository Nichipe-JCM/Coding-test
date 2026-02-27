#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> alpha(26);
    
    for(int i = 0; i < 26; i++){
        for(const auto k : keymap){
            for(int j = 0; j < k.length(); j++){
                if(k[j] == (char)(i + 'A')){
                    if(alpha[i] != 0 && j+1 > alpha[i]){
                        continue;
                    } else alpha[i] = j+1;
                }
            }
        }
    }
    
    for(const auto t : targets){
        int total = 0;
        bool isPossible = true;
        for(char c : t){
            if (alpha[c - 'A'] == 0){
                answer.push_back(-1);
                isPossible = false;
                break;
            }
            total += alpha[c - 'A'];
        }
        if (isPossible) answer.push_back(total);
    }
    return answer;
}