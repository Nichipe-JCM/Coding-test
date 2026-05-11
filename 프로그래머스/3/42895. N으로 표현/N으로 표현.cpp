#include <string>
#include <vector>
#include <set>

using namespace std;

void solveandadd(vector<set<int>>& nset, int index)
{
    if (index < 2) return;
    
    for(int i = 1; i < index; i++)
    {
        for(int i1 : nset[index - i])
        {
            for(int i2 : nset[i])
            {
                nset[index].insert(i1 + i2);
                nset[index].insert(i1 - i2);
                nset[index].insert(i1 * i2);
                nset[index].insert(i2 == 0 ? 0 : i1 / i2);
            }
        }
    }
}

int solution(int N, int number) {
    int answer = -1;
    if (N == number) return 1;
    vector<set<int>> nset(9);
    int NN = N;
    nset[1].insert(N);
    
    for(int i = 2; i <= 8; i++)
    {
        NN = NN * 10 + N;
        nset[i].insert(NN);
        solveandadd(nset, i);
        if (nset[i].find(number) != nset[i].end())
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}