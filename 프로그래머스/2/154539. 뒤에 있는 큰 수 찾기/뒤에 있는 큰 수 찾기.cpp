#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> index;
    index.push(0);
    for (int i = 1; i < numbers.size(); i++)
    {
        while (!index.empty() && numbers[index.top()] < numbers[i])
        {
            answer[index.top()] = numbers[i];
            index.pop();
        }
        index.push(i);
    }
    return answer;
}