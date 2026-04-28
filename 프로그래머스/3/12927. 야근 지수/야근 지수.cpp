#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq;
    int sum = 0;
    for(int i : works)
    {
        pq.push(i * 1LL);
        sum += i;
    }
    if (sum < n) return 0;
    
    for(int i = 0; i < n; i++)
    {
        long long top = pq.top();
        pq.pop();
        top--;
        pq.push(top);
    }
    while(!pq.empty())
    {
        long long ll = pq.top();
        pq.pop();
        answer += ll * ll;
    }
    return answer;
}