#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            answer += " ";
            continue;
        }
        if (i == 0 || s[i-1] == ' '){
            answer += toupper(s[i]);
        }
        else answer += tolower(s[i]);
    }
    return answer;
}