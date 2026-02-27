#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, const int& target, int& answer, int depth, int sum)
{
    if (depth == numbers.size())
    {
        if (sum == target) answer++;
        return;
    }
    
    dfs(numbers, target, answer, depth + 1, sum + numbers[depth]);
    dfs(numbers, target, answer, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer, 0, 0);
    return answer;
}