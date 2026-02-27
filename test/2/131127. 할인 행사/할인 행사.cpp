#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int days = 10;
    map<string, int> wantc;
    for(int i = 0; i < want.size(); i++){
        wantc[want[i]] = number[i];
    }
    for(int i = 0; i <= discount.size()-days; i++){
        vector<string> sub(discount.begin()+i, discount.begin()+i+days);
        map<string, int> submap;
        for(string s : sub){
            if(wantc.find(s) != wantc.end()){
                submap[s]++;
            }
            else break;
        }
        if (wantc == submap) answer++;
    }    
    return answer;
}