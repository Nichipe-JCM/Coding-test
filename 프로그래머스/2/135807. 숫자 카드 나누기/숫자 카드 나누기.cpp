#include <string>
#include <vector>
#include <numeric>

using namespace std;

int findvectorGCD(vector<int>& vec)
{
    if (vec.size() == 1) return vec[0];
    int result = vec[0];
    for(int i = 1; i < vec.size(); i++)
    {
        result = gcd(result, vec[i]);
        if (result == 1) return 1;
    }
    return result;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int GCDA = findvectorGCD(arrayA);
    int GCDB = findvectorGCD(arrayB);
    bool isagood = true, isbgood = true;
    for(const int& i : arrayA)
    {
        if (i % GCDB == 0)
        {
            isagood = false;
            break;
        }
    }
    for(const int& i : arrayB)
    {
        if (i % GCDA == 0)
        {
            isbgood = false;
            break;
        }
    }
    
    if (!isagood && !isbgood) return 0;
    if (isagood && !isbgood) return GCDB;
    if (isbgood && !isagood) return GCDA;
    return max(GCDA, GCDB);
}