#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int st = storey;
    while(true)
    {
        if (st <= 0) break;
        int currentfirst = st % 10;
        int currentsecond = (st % 100) / 10;
        if (0 <= currentfirst && currentfirst <= 4)
        {
            answer += currentfirst;
            st /= 10;
        }
        else if (6 <= currentfirst && currentfirst <= 9)
        {
            answer += 10 - currentfirst;
            st /= 10;
            st++;
        }
        else if (currentfirst == 5)
        {
            if (5 <= currentsecond)
            {
                answer += 10 - currentfirst;
                st /= 10;
                st++;
            }
            else
            {
                answer += currentfirst;
                st /= 10;
            }
        }
    }
    
    return answer;
}