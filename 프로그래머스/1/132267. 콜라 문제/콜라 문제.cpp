#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a){
        int given;
        given = b * (n / a);
        n = n - (a*(n/a)) + given;
        answer += given;
    }
    return answer;
}