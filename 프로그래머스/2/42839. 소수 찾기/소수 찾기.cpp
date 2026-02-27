#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

bool isprime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int depth, string cur, const string& numbers, vector<bool>& isused, unordered_set<int>& primeset)
{
    
    if (cur != "" && isprime(stoi(cur))) primeset.insert(stoi(cur));
    if (depth == numbers.length()) return;
    
    for(int i = 0; i < numbers.length(); i++)
    {
        if (isused[i]) continue;
        isused[i] = true;
        dfs(depth + 1, cur + numbers[i], numbers, isused, primeset);
        isused[i] = false;
    }
}
    

int solution(string numbers) {
    int answer = 0;
    vector<bool> isused(numbers.length());
    unordered_set<int> primeset;
    dfs(0, "", numbers, isused, primeset);
    answer = primeset.size();
    return answer;
}