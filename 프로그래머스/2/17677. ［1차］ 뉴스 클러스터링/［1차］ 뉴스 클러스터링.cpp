#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string tolowercase(string s){
    string temp = "";
    for(char c : s)
    {
        if (c >= 'A' && c <= 'Z') temp += c + 32;
        else temp += c;
    }
    return temp;
}

bool isalpha(char c)
{
    return (c >= 'a' && c <= 'z');
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> strset1, strset2;
    string fixstr1 = tolowercase(str1);
    string fixstr2 = tolowercase(str2);
    for(int i = 0; i < fixstr1.length() - 1; i++)
    {
        if (!isalpha(fixstr1[i]) || !isalpha(fixstr1[i + 1])) continue;
        string toadd = "";
        toadd += fixstr1[i];
        toadd += fixstr1[i + 1];
        strset1.push_back(toadd);
    }
    for(int i = 0; i < fixstr2.length() - 1; i++)
    {
        if (!isalpha(fixstr2[i]) || !isalpha(fixstr2[i + 1])) continue;
        string toadd = "";
        toadd += fixstr2[i];
        toadd += fixstr2[i + 1];
        strset2.push_back(toadd);
    }
    if (strset1.empty() && strset2.empty()) return 65536;
    int intersectioncount = 0, unioncount;
    unordered_map<string, int> str1map;
    unordered_map<string, int> str2map;
    for(string s : strset1) str1map[s]++;
    for(string s : strset2) str2map[s]++;
    
    for(const auto& pair : str1map)
    {
        string tocheck = pair.first;
        auto it = str2map.find(tocheck);
        if (it != str2map.end()) intersectioncount += min(pair.second, it->second);
    }
    unioncount = strset1.size() + strset2.size() - intersectioncount;
    answer = 65536 * ((float)intersectioncount / (float)unioncount);
    
    return answer;
}