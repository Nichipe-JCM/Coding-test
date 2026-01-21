#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string, int> repoCount;
    map<string, vector<string>> repoID;
    unordered_set<string> ban;
    
    for(string s : report){
        stringstream ss(s);
        string reporter;
        string reported;
        ss >> reporter >> reported;
        auto it = find(repoID[reporter].begin(), repoID[reporter].end(), reported);
        if (it != repoID[reporter].end()) continue;
        repoID[reporter].push_back(reported);
        repoCount[reported]++;
        if(repoCount[reported] >= k) ban.insert(reported);
    }
    
    for(int i = 0; i < id_list.size(); i++){
        for(string b : ban){
            auto it = find(repoID[id_list[i]].begin(), repoID[id_list[i]].end(), b);
            if (it != repoID[id_list[i]].end()) answer[i]++;
        }
    }
        
    return answer;
}

/*

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string, int> repoCount;
    map<string, unordered_set<string>> repoID;
    
    for(string s : report){
        stringstream ss(s);
        string reporter;
        string reported;
        ss >> reporter >> reported;
        if(repoID[reporter].insert(reported).second == true) repoCount[reported]++;
    }
    
    for(int i = 0; i < id_list.size(); i++){
        for(string id : repoID[id_list[i]]){
            if(repoCount[id] >= k) answer[i]++;
        }
    }
        
    return answer;
}

*/
