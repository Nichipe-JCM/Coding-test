#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int oddeven = 0;
    for(int i = 0; i < s.length(); i++, oddeven++){
        if(s[i] == ' '){
            answer += ' ';
            oddeven = -1;
            continue;
        }
        if(oddeven % 2 == 0 && 'a' <=s[i] && s[i] <= 'z'){
            answer += s[i] - ('a' - 'A');
            continue;
        }
        if(oddeven % 2 == 1 && 'A' <=s[i] && s[i] <= 'Z'){
            answer += s[i] + ('a' - 'A');
            continue;
        }
        answer += s[i];
    }
    return answer;
}