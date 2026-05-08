#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = -1;
    answer = num2 == 0 ? 0 : num1%num2;
    return answer;
}