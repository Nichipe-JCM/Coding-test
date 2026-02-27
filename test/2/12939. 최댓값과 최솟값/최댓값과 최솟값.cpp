#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    int min, max, temp;
    stringstream ss(s);
    ss >> min;
    ss >> temp;
    if (min < temp) max = temp;
    else {
        max = min;
        min = temp;
    }
    while(ss >> temp){
        if(min > temp) min = temp;
        if(max < temp) max = temp;
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}