#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isConvertable(const string& word1, const string& word2){
    int diffcount = 0;
    for(int i = 0; i < word1.size(); i++) if (word1[i] != word2[i]) diffcount++;
    return diffcount == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return 0;
    
    vector<bool> isused(words.size(), false);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty())
    {
        string currentword = q.front().first;
        int currentcount = q.front().second;
        q.pop();
        if (currentword == target)
        {
            answer = currentcount;
            break;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            if (isused[i]) continue;
            if (isConvertable(currentword, words[i]))
            {
                isused[i] = true;
                q.push({words[i], currentcount + 1});
            }
        }
    }
    return answer;
}