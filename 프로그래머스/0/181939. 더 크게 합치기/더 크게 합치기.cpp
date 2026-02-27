#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string tempa, tempb;
    string str_a = to_string(a);
    string str_b = to_string(b);
    tempa += str_a + str_b;
    tempb += str_b + str_a;
    if (stoi(tempa) > stoi(tempb)) {
        answer = stoi(tempa);
    }
    else answer = stoi(tempb);
    return answer;
}