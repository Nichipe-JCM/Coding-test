#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    vector<string> str;
    for(int i = 0; i < my_string.length();i++){
        str.push_back(my_string.substr(i));
    }
    auto it = find(str.begin(),str.end(),is_suffix);
    if(it == str.end()) return answer;
    else answer = 1;
    return answer;
}