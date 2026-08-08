#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    if (num_list.size() <= 10) answer++;
    for(int i = 0; i < num_list.size(); i++)
    {
        if (num_list.size() <= 10) answer *= num_list[i];
        else answer += num_list[i];
    }
    return answer;
}