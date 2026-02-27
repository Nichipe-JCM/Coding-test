#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long longd = d;
    
    for (long long x = 0; x <= d; x += k)
    {
        long long ymax = sqrt((longd*longd) - (x*x));
        long long ynum = (long long)(ymax / k) + 1;
        answer += ynum;        
    }
    return answer;
}