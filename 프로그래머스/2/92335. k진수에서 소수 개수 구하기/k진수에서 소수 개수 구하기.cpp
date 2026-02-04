#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long n)
{
    if (n <= 1) return false;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string kbase = "";
    string temp = "";
    
    while(n > 0)
    {
        int temp = n % k;
        kbase += to_string(temp);
        n /= k;
    }
    
    reverse(kbase.begin(), kbase.end());
    
    for (char c : kbase)
    {
        if (c == '0')
        {
            if (temp == "") continue;
            long long tempn = stoll(temp);
            if (isPrime(tempn)) answer++;
            temp = "";
            continue;
        }
        temp += c;
    }
    if (temp != "")
    {
        long long tempn = stoll(temp);
        if (isPrime(tempn)) answer++;
    }
    return answer;
}