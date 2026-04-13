#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1; // 자기 자신 그대로 표현하는 1 포함
    int start = 1;
    int end = 1;
    int sum = 1;
    while (start < n / 2 + 1)
    {
        if (sum == n)
        {
            answer++;
            end++;
            sum += end;
        }
        else if (sum > n)
        {
            sum -= start;
            start++;
        }
        else if (sum < n)
        {
            end++;
            sum += end;
        }
    }
    return answer;
}