#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long n : numbers)
    {
        if (n % 2 == 0)
        {
            answer.push_back(n + 1);
            continue;
        }
        
        long long bit = 1;
        while ((n & bit) != 0) bit *= 2;
        answer.push_back(n + bit - (bit / 2));
    }
    return answer;
}