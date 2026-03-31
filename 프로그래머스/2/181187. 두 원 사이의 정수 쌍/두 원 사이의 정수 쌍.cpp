#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long r1sq = (long long)r1 * r1;
    long long r2sq = (long long)r2 * r2;
    
    for(long long i = 1; i <= r2; i++)
    {
        long long isq = i * i;
        long long ymax = floor(sqrt(r2sq - isq));
        long long ymin;
        if (i > r1) ymin = 0;
        else ymin = ceil(sqrt(r1sq- isq));
        answer += (long long)(ymax - ymin + 1);
    }
    return answer * 4;
}