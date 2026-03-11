#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    if (s.front() == ')' || s.back() == '(') return false;
    stack<char> stk;
    for (const char& c : s)
    {
        if (c == '(') stk.push(c);
        else if (stk.empty()) return false;
        else stk.pop();
    }

    return stk.empty();
}