#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++){
        int div = 0;
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                if(j * j == i) div++;
                else div += 2;
            }
        }
        if (div > limit) answer += power;
        else answer += div;
    }
    return answer;
}