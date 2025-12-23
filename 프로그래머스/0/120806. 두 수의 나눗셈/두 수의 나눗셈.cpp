#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double dnum1 = num1, dnum2 = num2, danswer;
    danswer = dnum1 / dnum2 * 1000;
    answer = danswer;
    return answer;
}