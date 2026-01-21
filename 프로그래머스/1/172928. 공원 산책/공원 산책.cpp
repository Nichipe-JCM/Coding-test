#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    map<char,vector<int>> dir;
    int x, y;
    dir['E'] = {0,1};
    dir['W'] = {0,-1};
    dir['N'] = {-1,0};
    dir['S'] = {1,0};
    vector<int> answer;
    int width = park[0].length();
    int height = park.size();
    vector<vector<int>> dim(height, vector<int>(width, 0));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            switch(park[i][j]){
                case 'S':
                    dim[i][j] = 0;
                    x = j;
                    y = i;
                    break;
                case 'O':
                    dim[i][j] = 0;
                    break;
                case 'X':
                    dim[i][j] = 1;
                    break;
            }
        }
    }
    for (string s : routes){
        bool isOk = true;
        int tx = x;
        int ty = y;
        for(int i = 0; i < stoi(s.substr(2)); i++){
            if(ty + dir[s[0]][0] >= height || ty + dir[s[0]][0] < 0 ||
               tx + dir[s[0]][1] >= width || tx + dir[s[0]][1] < 0){
                isOk = false;
                break;
            }
            ty += dir[s[0]][0];
            tx += dir[s[0]][1];
            if(dim[ty][tx] == 1){
                isOk = false;
                break;
            }
        }
        if (isOk){
            x = tx;
            y = ty;
        }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}