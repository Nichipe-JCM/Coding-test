#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> hash;
    for (const string& s : phone_book)
    {
        hash.insert(s);
    }
    
    for (const string& s : phone_book)
    {
        for(int i = 1; i < s.length(); i++)
        {
            string subs = s.substr(0,i);
            auto it = hash.find(subs);
            if (it != hash.end()) return false;
        }
    }
    return answer;
}