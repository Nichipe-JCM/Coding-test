#include <string>
#include <vector>

using namespace std;

vector<long long> getdot(const vector<int>& a, const vector<int>& b){
    long long ax = a[0], ay = a[1], az = a[2];
    long long bx = b[0], by = b[1], bz = b[2];
    long long D = (ax * by) - (bx * ay);
    if (D == 0) return {};
    long long xtop = (ay * bz) - (by * az);
    long long ytop = (az * bx) - (bz * ax);
    if (xtop % D != 0 || ytop % D != 0) return {};
    long long xdot = xtop / D;
    long long ydot = ytop / D;
    return {xdot, ydot};
}

vector<string> solution(vector<vector<int>> line) {
    vector<vector<long long>> dot;
    for(int i = 0; i < line.size() - 1; i++)
    {
        for(int j = i + 1; j < line.size(); j++)
        {
            vector<long long> dotfromlines = getdot(line[i], line[j]);
            if (dotfromlines.empty()) continue;
            else dot.push_back(dotfromlines);
        }
    }
    
    long long xmin = dot[0][0], xmax = dot[0][0], ymin = dot[0][1], ymax = dot[0][1];
    for(const vector<long long>& vec : dot)
    {
        if (vec[0] < xmin) xmin = vec[0];
        else if (vec[0] > xmax) xmax = vec[0];
        if (vec[1] < ymin) ymin = vec[1];
        else if (vec[1] > ymax) ymax = vec[1];
    }
    
    long long width = xmax - xmin + 1;
    long long height = ymax - ymin + 1;
    string initdot(width, '.');
    vector<string> answer(height, initdot);
    for(const vector<long long>& vec : dot)
    {
        long long relativex = vec[0] - xmin;
        long long relativey = ymax - vec[1];
        answer[relativey][relativex] = '*';
    }
    
    return answer;
}