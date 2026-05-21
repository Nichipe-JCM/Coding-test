#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer = num_list;
    vector<int> temp;
    for(int i = n; i < answer.size(); i++) temp.push_back(answer[i]);
    for(int i = 0; i < n; i++) temp.push_back(answer[i]);
    answer = temp;
    return answer;
}