#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> stk;
    
    for(const char& c : s)
    {
        if (stk.empty())
        {
            stk.push(c);
            continue;
        }
        if (stk.top() == c)
        {
            stk.pop();
            continue;
        }
        else stk.push(c);
    }
    answer = stk.empty() ? 1 : 0;
    return answer;
}