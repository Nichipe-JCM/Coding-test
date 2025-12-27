#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    vector<string> vec;
    for(int i = 0; i <my_string.length() / m; i++){
        vec.push_back(my_string.substr(i * m,m));
    }
    for(int i = 0; i < vec.size(); i++){
        answer+=vec[i][c-1];
    }
    return answer;
}