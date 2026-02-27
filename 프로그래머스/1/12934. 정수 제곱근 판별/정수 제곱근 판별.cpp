#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long sqr = (long long)sqrt(n);
    if(sqr*sqr==n){
        answer =(sqr+1) * (sqr+1);
    } else answer = -1;
    return answer;
}