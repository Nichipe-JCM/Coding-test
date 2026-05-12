#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findparent(int i, vector<int>& parent){
    if (parent[i] == i) return i;
    return parent[i] = findparent(parent[i], parent);
}

void setunion(int a, int b, vector<int>& parent){
    int aparent = findparent(a, parent);
    int bparent = findparent(b, parent);
    
    if (aparent < bparent) parent[bparent] = aparent;
    else if(aparent > bparent) parent[aparent] = bparent;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[2] < b[2];
    });
    
    for(const vector<int>& vec : costs)
    {
        if (findparent(vec[0], parent) == findparent(vec[1], parent)) continue;
        
        setunion(vec[0], vec[1], parent);
        answer += vec[2];
    }
    
    return answer;
}