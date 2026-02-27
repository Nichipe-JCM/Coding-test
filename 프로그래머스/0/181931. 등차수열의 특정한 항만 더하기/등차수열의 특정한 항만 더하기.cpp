#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    vector<int> arith = {a};
    for(int i = 0; i < included.size() - 1; i++){
        arith.push_back(arith[i]+d);
    }
    for(int i = 0; i < included.size(); i++){
        if(included[i]){
            answer+= arith[i];
        }
    }
    return answer;
}