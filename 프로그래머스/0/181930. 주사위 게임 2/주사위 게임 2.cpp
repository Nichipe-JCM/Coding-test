#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    answer += a+b+c;
    if(a==b||b==c||a==c){
        if(a==b && a==c){
            answer *= (a*a*a) + (b*b*b) + (c*c*c);
        }
        answer *= (a*a)+(b*b)+(c*c);
    }
    return answer;
}