#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(true){
        answer++;
        if ((a-b==1&&a%2==0)||(b-a==1&&b%2==0)){
            break;
        }
        if (a%2 == 1){
            a = a/2+1;
        } else if (a!=1){
            a /= 2;
        }
        if (b%2 == 1){
            b = b/2+1;
        } else if (b!=1) {
            b /= 2;
        }
    }

    return answer;
}