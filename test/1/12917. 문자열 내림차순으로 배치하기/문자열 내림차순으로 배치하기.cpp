#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> vec;
    for(int i = 0; i < s.length(); i++){
        vec.push_back(s[i]);
    }
    sort(vec.rbegin(), vec.rend());
    for(auto c : vec){
        answer += c;
    }
    return answer;
}