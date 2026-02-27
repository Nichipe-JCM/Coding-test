#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> cmap;
    
    for (const vector<string> s : clothes)
    {
        cmap[s[1]]++;
    }
    
    for (const auto pair : cmap)
    {
        answer *= pair.second + 1;
    }
 
    return answer - 1;
}