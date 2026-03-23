#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkuniqueness (const vector<vector<string>>& relation, int current, int rowcount, int colcount){
    unordered_set<string> unique;
    
    for(int i = 0; i < rowcount; i++)
    {
        string data = "";
        for(int j = 0; j < colcount; j++)
        {
            if (current & (1 << j)) data += relation[i][j];
        }
        unique.insert(data);
    }
    if (unique.size() == rowcount) return true;
    else return false;
}

bool checkminimality (int i, const vector<int>& passedkey){
    for(int key : passedkey)
    {
        if ((i & key) == key) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowcount = relation.size();
    int colcount = relation[0].size();
    vector<int> passedkey;
    for(int i = 0; i < (1 << colcount); i++)
    {
        if (checkuniqueness(relation, i, rowcount, colcount) && checkminimality(i, passedkey))
            passedkey.push_back(i);
    }
    answer = passedkey.size();
    return answer;
}