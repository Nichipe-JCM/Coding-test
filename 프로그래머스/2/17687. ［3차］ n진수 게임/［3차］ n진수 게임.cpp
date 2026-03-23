#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string tobase(int num, int n){
    if (num == 0) return "0";
    
    string result = "";
    string numbers = "0123456789ABCDEF";
    
    while (num > 0)
    {
        result += numbers[num % n];
        num /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string fullnumbers = "";
    int totalnumbercount = t * m;
    for(int i = 0; fullnumbers.size() < totalnumbercount; i++)
    {
        fullnumbers += tobase(i, n);
    }
    for(int i = p - 1; i < fullnumbers.size(); i += m)
    {
        answer += fullnumbers[i];
        if (answer.size() == t) break;
    }
    return answer;
}