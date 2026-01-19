#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> score = {-3,-2,-1,0,1,2,3};
    vector<char> type = {'R','T','C','F','J','M','A','N'};
    vector<int> typescore(8,0);
    for(int i = 0; i < survey.size(); i++){
        if(survey[i] == "RT"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[0] += score[choices[i]-1];
            else typescore[1] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "TR"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[1] += score[choices[i]-1];
            else typescore[0] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "FC"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[2] += score[choices[i]-1];
            else typescore[3] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "CF"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[3] += score[choices[i]-1];
            else typescore[2] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "MJ"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[4] += score[choices[i]-1];
            else typescore[5] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "JM"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[5] += score[choices[i]-1];
            else typescore[4] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "AN"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[6] += score[choices[i]-1];
            else typescore[7] += score[choices[i]-1];
            continue;
        }
        if(survey[i] == "NA"){
            if(choices[i] == 0) continue;
            if(choices[i] < 0) typescore[7] += score[choices[i]-1];
            else typescore[6] += score[choices[i]-1];
            continue;
        }
    }
    
    if (typescore[0]>typescore[1]) answer+='R';
    else if (typescore[0]<typescore[1]) answer+='T';
    else answer+='R';
    if (typescore[2]>typescore[3]) answer+='F';
    else if (typescore[2]<typescore[3]) answer+='C';
    else answer+='C';
    if (typescore[4]>typescore[5]) answer+='M';
    else if (typescore[4]<typescore[5]) answer+='J';
    else answer+='J';
    if (typescore[6]>typescore[7]) answer+='A';
    else if (typescore[6]<typescore[7]) answer+='N';
    else answer+='A';
    
    return answer;
}