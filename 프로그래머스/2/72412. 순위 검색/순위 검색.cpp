#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> counts;



void dfs(const vector<string>& infovec, int score, int depth, string current){
    if (depth == 4)
    {
        counts[current].push_back(score);
        return;
    }
    
    dfs(infovec, score, depth + 1, current + infovec[depth]);
    dfs(infovec, score, depth + 1, current + '-');
}

void addtocounts (const string& info){
    string lang, job, exp, food;
    string dump;
    int score;
    stringstream ss(info);
    ss >> lang >> job >> exp >> food >> score;
    vector<string> infovec = {lang, job, exp, food};
    dfs(infovec, score, 0, "");
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    
    for(const string& s : info) addtocounts(s);
    
    for(auto& pair : counts) sort(pair.second.begin(), pair.second.end());
    
    for(int i = 0; i < query.size(); i++)
    {
        string lang, job, exp, food;
        string dump;
        int score;
        stringstream ss(query[i]);
        ss >> lang >> dump >> job >> dump >> exp >> dump >> food >> score;
        string tosearch = lang + job + exp + food;
        auto it = lower_bound(counts[tosearch].begin(), counts[tosearch].end(), score);
        int index = it - counts[tosearch].begin();
        answer[i] = counts[tosearch].size() - index;
    }
    return answer;
}