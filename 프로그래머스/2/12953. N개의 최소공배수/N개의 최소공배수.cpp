#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int a = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int b = arr[i];
        a = lcm(a,b);
    }
    answer = a;
    return answer;
}