#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    vector<char> vec;
    for(int i = 0; i < str.length(); i++){
        vec.push_back(str[i]);
    }
    sort(vec.begin(), vec.end(), greater<>());
    str = "";
    for(int i = 0; i < vec.size(); i++){
        str += vec[i];
    }
    answer = stoll(str);
    
    return answer;
}