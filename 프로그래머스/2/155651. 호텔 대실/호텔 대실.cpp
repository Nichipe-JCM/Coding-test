#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<int>> intbooktime(book_time.size(), vector<int>(2));
    for(int i = 0; i < book_time.size(); i++)
    {
        intbooktime[i][0] = (stoi(book_time[i][0].substr(0,2)) * 60) + stoi(book_time[i][0].substr(3,2));
        intbooktime[i][1] = (stoi(book_time[i][1].substr(0,2)) * 60) + stoi(book_time[i][1].substr(3,2)) + 10;
    }
    sort (intbooktime.begin(), intbooktime.end());
    priority_queue<int, vector<int>, greater<int>> rooms;
    for(const vector<int>& vec : intbooktime)
    {
        if (rooms.empty())
        {
            rooms.push(vec[1]);
            continue;
        }
        if (rooms.top() <= vec[0])
        {
            rooms.pop();
            rooms.push(vec[1]);
        }
        else
        {
            rooms.push(vec[1]);
        }
    }
    
    answer = rooms.size();
    
    return answer;
}