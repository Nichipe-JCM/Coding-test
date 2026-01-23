#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long n0 = 0;
    long long n1 = 1;
    long long nn;
    
    for(int i = 2;i <= n; i++){
        nn = (n1 + n0) % 1234567;
        n0 = n1;
        n1 = nn;
    }
    answer = nn;
    return answer;
}