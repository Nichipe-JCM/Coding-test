#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string odd;
    string even;
    for(auto& num : num_list){
        if(num%2 == 1){
            odd+=to_string(num);
        }else even+=to_string(num);
    }
    answer = stoi(odd)+stoi(even);
    return answer;
}