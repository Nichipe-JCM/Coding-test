#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int alphabet(const char& c)
{
    int num = c - 'A';
    return min(num, 26 - num);
}

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int route1 = length - 1;
    
    for (int i = 0; i < length; i++)
    {
        answer += alphabet(name[i]);
        int nexti = i + 1;
        while (nexti < length && name[nexti] == 'A') nexti++;
        int route2 = i + i + length - nexti;
        int route3 = (length - nexti) * 2 + i;
        route1 = min({route1, route2, route3});
    }
    answer += route1;
    return answer;
}