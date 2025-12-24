#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    while(true){
        if(temp == 1) break;
        if(answer >= 500) return -1;
        if(temp%2 ==0){
            temp /= 2;
            answer+=1;
        } else {
            temp = temp*3+1;
            answer+=1;
        }
    }
    return answer;
}