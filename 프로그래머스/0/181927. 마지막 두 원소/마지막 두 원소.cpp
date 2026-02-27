#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    if (num_list[num_list.size()-2] < num_list[num_list.size()-1]){
        num_list.push_back((num_list[num_list.size()-1])-(num_list[num_list.size()-2]));
    } else{
        num_list.push_back(num_list[num_list.size()-1]*2);
    }
    answer = num_list;
    return answer;
}