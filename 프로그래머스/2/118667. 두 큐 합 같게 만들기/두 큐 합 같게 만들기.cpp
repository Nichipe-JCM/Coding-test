#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long q1sum = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long q2sum = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long totalsum = q1sum + q2sum;
    if (totalsum % 2 == 1) return -1;
    
    int q1index = 0, q2index = 0;
    int trylimit = (queue1.size() + queue2.size()) * 2;
    while (true)
    {
        if (answer > trylimit) return -1;
        if (q1sum == q2sum) break;
        if (q1sum > q2sum)
        {
            long long numtomove = queue1[q1index];
            queue2.push_back(numtomove);
            q1index++;
            answer++;
            q1sum = q1sum - numtomove;
            q2sum = q2sum + numtomove;
        }
        else if (q2sum > q1sum)
        {
            long long numtomove = queue2[q2index];
            queue1.push_back(numtomove);
            q2index++;
            answer++;
            q1sum = q1sum + numtomove;
            q2sum = q2sum - numtomove;
        }
    }
    return answer;
}