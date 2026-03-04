#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> time;
    time.push(0);
    for(int i = 1; i < prices.size(); i++)
    {
        while (!time.empty() && prices[i] < prices[time.top()])
        {
            answer[time.top()] = i - time.top();
            time.pop();
        }
        time.push(i);
    }
    while (!time.empty())
    {
        answer[time.top()] = prices.size() - 1 - time.top();
        time.pop();
    }
    return answer;
}