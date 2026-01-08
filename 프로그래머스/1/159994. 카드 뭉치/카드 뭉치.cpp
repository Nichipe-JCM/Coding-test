#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int point1 = 0;
    int point2 = 0;
    int pointg = 0;
    int goalSize = goal.size();
    while(true){
        if(cards1[point1] == goal[pointg]){
            point1++;
            pointg++;
        } else if (cards2[point2] == goal[pointg]){
            point2++;
            pointg++;
        } else return "No";
        if (pointg == goalSize) return "Yes";
    }
}