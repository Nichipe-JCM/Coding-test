#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s.length() == 1) return s;
    if(s.length() % 2 == 0){
        for(int i = 0; i < s.length(); i++){
            if (i == s.length()/2-1 || i == s.length()/2) answer+=s[i];
        }
    } else{
        for(int i = 0; i < s.length(); i++){
            if (i == s.length()/2) answer+=s[i];
        }
    }
    return answer;
}