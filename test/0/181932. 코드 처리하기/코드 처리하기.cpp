#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    string ret = "";
    for (int i = 0; i < code.length(); i++) {
        if (mode == 0 && i % 2 == 0 && code[i] != '1') {
            ret += code[i];
        }
        else if (mode == 1 && i % 2 == 1 && code[i] != '1') {
            ret += code[i];
        }
        if (code[i] == '1') {
            if (mode == 0) {
                mode = 1;
            }
            else mode = 0;
        }
    }
    if (ret == "") {
        answer = "EMPTY";
    }
    else answer = ret;
    return answer;
}

int main() {
    solution("abc1abc1abc");
    return 0;
}