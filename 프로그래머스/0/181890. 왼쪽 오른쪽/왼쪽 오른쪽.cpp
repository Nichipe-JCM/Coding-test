#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    vector<string> temp;
    bool found = false;
    for(const string& s : str_list)
    {
        if (s == "l" && !found)
        {
            found = true;
            break;
        }
        else if (s == "r" && !found)
        {
            found = true;
            temp.clear();
        }
        else temp.push_back(s);
    }
    if (found) answer = temp;
    return answer;
}