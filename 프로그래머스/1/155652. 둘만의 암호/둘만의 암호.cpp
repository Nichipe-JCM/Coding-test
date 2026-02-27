#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> vec(26);
    for(char c : skip){
        vec[c - 'a'] = 1;
    }
    for(char c2 : s){
        for(int i = 0; i < index; i++){
            c2 += 1;
            if(c2 > 'z') c2 = 'a';
            while(vec[c2-'a'] == 1){
                c2 += 1;
                if(c2 > 'z') c2 = 'a';
            }
        }
        answer+= c2;
    }
    return answer;
}