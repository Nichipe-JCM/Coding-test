#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    vector<int> vec = {a, b};
    sort (vec.begin(), vec.end());
    for(int i = vec[0]; i <= vec[1];i++){
        answer += i;
    }
    return answer;
}