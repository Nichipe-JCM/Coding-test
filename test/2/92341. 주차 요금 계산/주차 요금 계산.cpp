#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int timeToMin(string time)
{
    int hrs = 0;
    int mins = 0;
    string temp = "";
    for(char c : time)
    {
        if (c == ':')
        {
            hrs = stoi(temp);
            temp = "";
            continue;
        }
        temp += c;
    }
    mins = hrs * 60 + stoi(temp);
    return mins;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> inmap;
    map<int, int> outmap;
    
    for (string s : records)
    {
        string timestr, type;
        int car, time;
        stringstream ss(s);
        ss >> timestr >> car >> type;
        time = timeToMin(timestr);
        if (type == "IN")
        {
            inmap[car] = time;
        }
        if (type == "OUT")
        {
            outmap[car] += time - inmap[car];
            inmap.erase(car);
        }
    }
    
    if (!inmap.empty())
    {
        for (pair p : inmap)
        {
            outmap[p.first] += timeToMin("23:59") - p.second;
        }
    }
    
    for (pair p : outmap)
    {
        if (p.second <= fees[0]) answer.push_back(fees[1]);
        else
        {
            answer.push_back(ceil((double)(p.second - fees[0]) / fees[2]) * fees[3] + fees[1]);
        }
    }
    
    return answer;
}