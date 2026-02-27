#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(), [=](string a, string b){
        if(a[n] < b[n]) return true;
        if(a[n] > b[n]) return false;
        return a < b;
    });
    answer = strings;
    return answer;
}