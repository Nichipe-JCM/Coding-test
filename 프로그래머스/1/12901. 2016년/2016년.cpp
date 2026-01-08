#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    for(int i = 1; i <= a; i++){
        if(i == 3) b += 29;
        else if (i == 2 || i == 4 || i == 6 || i == 8 || i == 9 || i == 11) b += 31;
        else if (i == 5 || i == 7 || i == 10 || i == 12) b += 30;
    }
    answer = day[b%7];
    return answer;
}