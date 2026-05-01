#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    unordered_map<int, int> validcount;
    
    for(const string& s : operations)
    {
        char op = s[0];
        int num = stoi(s.substr(2));
        
        if (op == 'I')
        {
            maxpq.push(num);
            minpq.push(num);
            validcount[num]++;
        }
        else
        {
            if (num == 1)
            {
                while(!maxpq.empty() && validcount[maxpq.top()] == 0) maxpq.pop();
                if (!maxpq.empty())
                {
                    validcount[maxpq.top()]--;
                    maxpq.pop();
                }
            }
            else if (num == -1)
            {
                while(!minpq.empty() && validcount[minpq.top()] == 0) minpq.pop();
                if (!minpq.empty())
                {
                    validcount[minpq.top()]--;
                    minpq.pop();
                }
            }
        }
    }
    while(!maxpq.empty() && validcount[maxpq.top()] == 0) maxpq.pop();
    while(!minpq.empty() && validcount[minpq.top()] == 0) minpq.pop();
    if (maxpq.empty() && minpq.empty()) return {0, 0};
    else return {maxpq.top(), minpq.top()};
}