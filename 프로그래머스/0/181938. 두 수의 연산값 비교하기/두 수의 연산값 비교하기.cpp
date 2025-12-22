#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string temp = to_string(a) + to_string(b);
    if (stoi(temp) > 2 * a * b){
        answer = stoi(temp);
    } else answer = 2 * a * b;
    return answer;
}