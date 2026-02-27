#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000000};
    int start = 0, end = 0, sum = sequence[0];
    
    while (end < sequence.size())
    {
        if (sum < k)
        {
            end++;
            if (end < sequence.size()) sum += sequence[end];
            continue;
        }
        if (sum > k)
        {
            sum -= sequence[start];
            start++;
            continue;
        }
        if (sum == k)
        {
            int length = end - start;
            int answerlength = answer[1] - answer[0];
            if (length < answerlength)
            {
                answer[0] = start;
                answer[1] = end;
            }
            sum -= sequence[start];
            start++;
        }
    }
    return answer;
}