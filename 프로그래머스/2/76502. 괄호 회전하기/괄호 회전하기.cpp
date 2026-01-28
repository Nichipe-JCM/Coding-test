#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++){
        s += s[0];
        s.erase(0,1);
        int sopen = 0;
        int mopen = 0;
        int bopen = 0;
        bool isvalid = true;
        vector<char> vec;
        for(int j = 0; j < s.length(); j++){
            char c = s[j];
            switch(c){
                case '{':
                    bopen++;
                    vec.push_back('{');
                    break;
                case '[':
                    mopen++;
                    vec.push_back('[');
                    break;
                case '(':
                    sopen++;
                    vec.push_back('(');
                    break;
                case '}':
                    if(bopen > 0 && vec.back() == '{'){
                        bopen--;
                        vec.pop_back();
                        break;
                    } else {
                        isvalid = false;
                        break;
                    }
                case ']':
                    if(mopen > 0 && vec.back() == '['){
                        mopen--;
                        vec.pop_back();
                        break;
                    } else {
                        isvalid = false;
                        break;
                    }
                case ')':
                    if(sopen > 0 && vec.back() == '('){
                        sopen--;
                        vec.pop_back();
                        break;
                    } else {
                        isvalid = false;
                        break;
                    }
            }
            if(!isvalid) break;
        }
        if(sopen == 0 && mopen == 0 && bopen == 0 && isvalid) answer++;
    }
    return answer;
}