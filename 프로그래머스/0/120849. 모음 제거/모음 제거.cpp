#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<char> a = {'a', 'e', 'i', 'o', 'u'};
    for(char c : my_string)
    {
        auto it = find(a.begin(), a.end(), c);
        if (it == a.end()) answer += c;
    }
    return answer;
}