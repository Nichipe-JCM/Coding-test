#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termmap;
    int curday = (stoi(today.substr(0,4))*12*28)+
        (stoi(today.substr(5,2))*28)+
        stoi(today.substr(8,2));
    for(string t : terms){
        termmap[t[0]] = stoi(t.substr(2))*28;
    }
    for(int i = 0; i < privacies.size(); i++){
        int privday = (stoi(privacies[i].substr(0,4))*12*28)+
            (stoi(privacies[i].substr(5,2))*28)+
            stoi(privacies[i].substr(8,2));
        auto it = termmap.find(privacies[i].back());
        if (privday + it->second <= curday) {
            answer.push_back(i+1);
        }
    }
    return answer;
}