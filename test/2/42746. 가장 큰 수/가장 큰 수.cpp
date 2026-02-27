#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strnums;
    
    for (int i : numbers) strnums.push_back(to_string(i));
    
    sort(strnums.begin(), strnums.end(), [](const string& a, const string& b)
         {
             return a + b > b + a;
         });
    
    for (const string& s : strnums) answer += s;
    
    if (answer[0] == '0') return "0";
    
    return answer;
}