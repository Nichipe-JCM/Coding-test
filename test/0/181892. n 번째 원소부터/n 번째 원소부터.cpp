#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    for(int i = 0; i < num_list.size()-n+1; i++){
        answer.push_back(num_list[n-1+i]);
    }
    return answer;
}