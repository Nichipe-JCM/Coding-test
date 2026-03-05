#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> operators;
    string tempnum = "";
    for(int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+')
        {
            numbers.push_back(stoll(tempnum));
            tempnum = "";
            operators.push_back(expression[i]);
        }
        else tempnum += expression[i];
    }
    numbers.push_back(stoll(tempnum));
    
    vector<char> prio = {'+', '*', '-'};
    sort(prio.begin(), prio.end());
    
    do{
        vector<long long> tempnums = numbers;
        vector<char> tempoper = operators;
        for(int i = 0; i < prio.size(); i++)
        {
            char optofind = prio[i];
            for(int j = 0; j < tempoper.size();)
            {
                if (tempoper[j] == optofind)
                {
                    long long calc;
                    if (optofind == '+') calc = tempnums[j] + tempnums[j + 1];
                    else if (optofind == '-') calc = tempnums[j] - tempnums[j + 1];
                    else if (optofind == '*') calc = tempnums[j] * tempnums[j + 1];
                    tempnums[j] = calc;
                    tempoper.erase(tempoper.begin() + j);
                    tempnums.erase(tempnums.begin() + j + 1);
                }
                else j++;
            }
        }
        answer = max(answer, llabs(tempnums[0]));
    }while (next_permutation(prio.begin(), prio.end()));
    
    return answer;
}