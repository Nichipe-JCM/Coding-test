#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> hashmap;
    for (const string& s : record)
    {
        stringstream ss(s);
        string act = "", uid = "", name = "";
        ss >> act >> uid >> name;
        if (act == "Enter") hashmap[uid] = name;
        else if (act == "Change") hashmap[uid] = name;
    }
    
    for (const string& s : record)
    {
        stringstream ss(s);
        string act = "", uid = "", name = "";
        ss >> act >> uid >> name;
        if (act == "Enter") answer.push_back(hashmap[uid] + "님이 들어왔습니다.");
        else if (act == "Leave") answer.push_back(hashmap[uid] + "님이 나갔습니다.");
    }
    return answer;
}