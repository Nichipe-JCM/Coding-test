#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> temp;
    for(int i = 0; i < number.length(); i++)
    {
        while (!temp.empty() && temp.top() < number[i] && k > 0)
        {
                temp.pop();
                k--;
        }
        temp.push(number[i]);
    }
    while(k > 0)
    {
        temp.pop();
        k--;
    }
    while(!temp.empty())
    {
        answer += temp.top();
        temp.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}