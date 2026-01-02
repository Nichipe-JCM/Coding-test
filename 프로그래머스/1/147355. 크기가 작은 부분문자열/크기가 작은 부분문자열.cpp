#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<string> vec;
    if(p.length() == 1 && t.length() == 1){
        if(t <= p) return 1;
        else return 0;
    }
    for(int i = 0; i < t.length() - p.length()+1; i++){
        vec.push_back(t.substr(i, p.length()));
    }
    for(string s : vec){
        if(stoll(s) <= stoll(p)) answer++;
    }
    return answer;
}