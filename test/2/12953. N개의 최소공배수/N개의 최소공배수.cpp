#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int a = arr[0];
    int gcd;
    for(int i = 1; i < arr.size(); i++){
        int b = arr[i];
        int tempa = a;
        int tempb = b;
        while(true){
            int r = tempa % tempb;
            if(r == 0){
                gcd = tempb;
                break;
            }
            else{
                tempa = tempb;
                tempb = r;
            }
        }
        a = (a / gcd) * b;
    }
    answer = a;
    return answer;
}