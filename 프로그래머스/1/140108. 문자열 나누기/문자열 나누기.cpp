#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    int same = 1, notsame = 0;
    if (s.length() == 1) return 1;
    for(int i = 1; i <= s.length(); i++){
        if(i == s.length()){
            answer++;
            break;
        }
        if(s[i] == x){
            same++;
        } else if (same!=notsame){
            notsame++;
            if(same == notsame){
                same = 1;
                notsame = 0;
                i++;
                x = s[i];
                answer++;
            }
        }
    }
    return answer;
}