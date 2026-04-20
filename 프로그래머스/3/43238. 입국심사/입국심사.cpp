#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    auto minmax = minmax_element(times.begin(), times.end());
    long long mintime = *minmax.first;
    long long maxtime = (long long)*minmax.second * n;
    cout << maxtime;
    while(mintime <= maxtime)
    {
        long long median = (mintime + maxtime) / 2;
        long long passed = 0;
        for(int i : times) passed += median / i;
        if (passed >= n)
        {
            answer = median;
            maxtime = median - 1;
        }
        else mintime = median + 1;
    }
    return answer;
}