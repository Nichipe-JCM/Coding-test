#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> pmap;
    for(int i = 0; i < players.size(); i++){
        pmap[players[i]] = i;
    }
    for(string c : callings){
        int currank = pmap[c];
        string frontp = players[currank-1];
        swap(players[currank], players[currank-1]);
        pmap[c] = currank-1;
        pmap[frontp] = currank;
    }
    answer = players;
    return answer;
}