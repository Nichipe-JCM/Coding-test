#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str;
    vector<string> vec = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9') str += s[i];
        else{
            for(int j = 0; j<vec.size();j++){
                if(vec[j] == s.substr(i,vec[j].length())){
                    str += to_string(j);
                    i += vec[j]. length()-1;
                    break;
                }
            }
        }
    }
    answer = stoi(str);
    return answer;
}