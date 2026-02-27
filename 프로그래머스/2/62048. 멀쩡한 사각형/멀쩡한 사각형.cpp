#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long longw = w, longh = h;
    int GCD = gcd(w,h);
    long long size = longw * longh;
    
    int wmin = w / GCD;
    int hmin = h / GCD;
    int mindisabled = wmin + hmin - 1;
    long long disabled = mindisabled * GCD;
    
    answer = size - disabled;
    return answer;
}