#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    int width, height;
    for(int i = 3; i * i <= total; i++){
        if(total % i == 0){
            int tempw = i;
            int temph = total / i;
            if((tempw-2) * (temph-2) == yellow){
                width = tempw;
                height = temph;
                break;
            }
        }
    }
    answer = {max(width, height), min(width, height)};
    return answer;
}