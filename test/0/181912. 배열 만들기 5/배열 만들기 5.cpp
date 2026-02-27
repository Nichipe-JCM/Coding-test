#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for (int i = 0; i < intStrs.size(); i++) {
        string str = "";
        for (int j = s; j < s + l; j++) {
            str += intStrs[i][j];
        }
        if (stoi(str) > k) answer.push_back(stoi(str));
    }
    return answer;
}