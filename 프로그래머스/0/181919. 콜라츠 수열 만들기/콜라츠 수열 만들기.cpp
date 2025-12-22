#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(n);
    for(;;){
        if(n%2==0){
            n /= 2;
            answer.push_back(n);
        } else {
            n = 3*n+1;
            answer.push_back(n);
        }
        if(n == 1){
            break;
        }
    }
    return answer;
}