#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s){
        if (c == ' '){
            answer+= ' ';
            continue;
        }
        if (c + n > 'z' || (c + n > 'Z'&&c < 'a')){
            answer+= c+n-26;
        } else answer+= c+n;
    }
    return answer;
}