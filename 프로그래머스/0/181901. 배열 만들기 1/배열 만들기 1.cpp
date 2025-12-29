#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    int count = 1;
    while(true){
        if(k*count>n) break;
        answer.push_back(k*count);
        count++;
    }
    return answer;
}