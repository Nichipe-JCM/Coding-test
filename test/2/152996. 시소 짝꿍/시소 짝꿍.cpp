#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<long long> count(1001, 0);
    for(long long i = 0; i < weights.size(); i++)
    {
        count[weights[i]]++;
    }
    
    for(long long i = 100; i < count.size(); i++)
    {
        long long caseA; // 동일
        long long caseB; // 3:2
        long long caseC; // 4:2
        long long caseD; // 4:3
        
        caseA = count[i] * (count[i] - 1) / 2;
        if (i % 2 != 0 || i * 3 / 2 > 1000) caseB = 0;
        else caseB = count[i] * count[i * 3 / 2];
        if (i > 500) caseC = 0;
        else caseC = count[i] * count[i * 2];
        if (i % 3 != 0 || i * 4 / 3 > 1000 ) caseD = 0;
        else caseD = count[i] * count[i * 4 / 3];
        
        answer += caseA + caseB + caseC + caseD;
    }
    
    return answer;
}