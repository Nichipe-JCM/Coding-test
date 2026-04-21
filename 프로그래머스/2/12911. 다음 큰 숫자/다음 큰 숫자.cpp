#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;
    int onecount = bitset<32>(n).count();
    for(int i = 1;;i++)
    {
        if (onecount == bitset<32>(n + i).count())
        {
            answer = n + i;
            break;
        }
    }
    return answer;
}