#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int a = 0, b = 0, c = 0, d = 0, e = 0, sum = 0;
    if (x >= 10000) e = 1;
    if (x >= 1000) d = (x%10000)/1000;
    if (x >= 100) c = (x%1000)/100;
    if (x >= 10) b = (x%100)/10;
    if (x >= 1) a = x%10;
    sum = a+b+c+d+e;
    if(x%sum==0) answer = true;
    return answer;
}