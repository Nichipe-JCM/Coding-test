#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    for(int i = 0; i < str.length(); i++){
        answer.push_back(str[str.length() -1 -i] - '0');
    }
    return answer;
}