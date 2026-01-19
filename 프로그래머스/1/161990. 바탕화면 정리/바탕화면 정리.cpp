#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = -1;
    int luy = -1;
    int rdx = -1;
    int rdy = -1;
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '.') continue;
            if(wallpaper[i][j] == '#'){
                if(lux == -1) lux = i;
                else if(lux > i) lux = i;
                if(luy == -1) luy = j;
                else if(luy > j) luy = j;
                if(rdx == -1) rdx = i+1;
                else if(rdx < i+1) rdx = i+1;
                if(rdy == -1) rdy = j+1;
                else if(rdy < j+1) rdy = j+1;
            }
        }
    }
    answer = {lux, luy, rdx, rdy};
    
    return answer;
}