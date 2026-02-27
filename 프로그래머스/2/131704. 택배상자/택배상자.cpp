#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> subline;
    int current = 0;
    
    for(int i = 1; i <= order.size(); i++)
    {
        subline.push(i);
        while (!subline.empty() && subline.top() == order[current])
        {
            answer++;
            current++;
            subline.pop();
        }
    }
    return answer;
}