#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    int p1c = 0, p1v = 0;
    int p2c = 0, p2v = 0;
    int p3c = 0, p3v = 0;
    for(int a : answers){
        if(p1[p1v] == a) p1c++;
        if(p2[p2v] == a) p2c++;
        if(p3[p3v] == a) p3c++;
        p1v++;
        p2v++;
        p3v++;
        if(p1v == 5) p1v = 0;
        if(p2v == 8) p2v = 0;
        if(p3v == 10) p3v = 0;
    }
    if(p1c == p2c && p1c == p3c){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    } else if(p1c == p2c && p1c > p3c){
        answer.push_back(1);
        answer.push_back(2);
        return answer;
    } else if (p1c == p3c && p1c > p2c){
        answer.push_back(1);
        answer.push_back(3);
        return answer;
    } else if (p2c == p3c && p2c > p1c){
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    } else if(p1c == max({p1c,p2c,p3c})){
        answer.push_back(1);
        return answer;
    } else if(p2c == max({p1c,p2c,p3c})){
        answer.push_back(2);
        return answer;
    } else if(p3c == max({p1c,p2c,p3c})){
        answer.push_back(3);
        return answer;
    }
}