#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> can = {"aya","ye","woo","ma"};
    for(string b : babbling){
        bool found = false;
        if(b.length()<=3){
            auto it = find (can.begin(), can.end(), b);
            if(it != can.end()){
                answer++;
                continue;
            } else continue;
        }
        int pos = 0;
        string prev = "";
        while(pos<b.length()){
            if (pos + 2 > b.length()) break;
            auto it3 = find (can.begin(), can.end(), b.substr(pos,2));
            if (it3 != can.end()){
                if(pos>=2 && b.substr(pos,2) == prev) break;
                found = true;
                prev = b.substr(pos,2);
                pos+=2;
                continue;
            } else found = false;
            auto it2 = find (can.begin(), can.end(), b.substr(pos,3));
            if (it2 != can.end()){
                if(pos>=3 && b.substr(pos,3) == prev) break;
                found = true;
                prev = b.substr(pos,3);
                pos+=3;
                continue;
            } else found = false;
            if (!found) break;
        }
        if(pos>=b.length()) answer++;
    }
    return answer;
}