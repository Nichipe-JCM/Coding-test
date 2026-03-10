#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1001;
    int length = s.length();
    string tocheck;
    int curcount = 0;
    for(int i = 1; i <= length; i++)
    {
        tocheck = s.substr(0, i);
        curcount = 1;
        string result = "";
        for(int j = i; j < length; j += i)
        {
            string current = s.substr(j, i);
            
            if (current == tocheck)
            {
                curcount++;
            }
            else
            {
                if (curcount == 1)
                {
                    result += tocheck;
                    tocheck = current;
                }
                else
                {
                    string toadd = to_string(curcount) + tocheck;
                    result += toadd;
                    tocheck = current;
                    curcount = 1;
                }
            }
        }
        if (curcount == 1)
        {
            result += tocheck;
        }
        else
        {
            string toadd = to_string(curcount) + tocheck;
            result += toadd;
        }
        answer = min(answer, (int)result.length());
    }
    return answer;
}