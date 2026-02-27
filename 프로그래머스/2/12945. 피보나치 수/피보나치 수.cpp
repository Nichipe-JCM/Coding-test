#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int n0 = 0;
    int n1 = 1;
    int nn;
    
    for(int i = 2;i <= n; i++){
        nn = (n1 + n0) % 1234567;
        n0 = n1;
        n1 = nn;
    }
    answer = nn;
    return answer;
}