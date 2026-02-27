#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = "";
    while (n > 1) {
        str += to_string(n % 3);
        n /= 3;
    }
    if (n == 1) str += '1';
    reverse(str.begin(), str.end());
    int pow = 1;
    for(int i = 0; i < str.length(); i++){
        answer += (str[i] - '0') * pow;
        pow *= 3;
    }
    return answer;
}