#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int vilnum, int N, int K, int distsum, const vector<vector<pair<int, int>>>& map, vector<int>& dist)
{
    if (distsum > dist[vilnum] || distsum > K) return;
    
    dist[vilnum] = distsum;
    
    for(const pair<int, int>& pair : map[vilnum])
    {
        int nextvil = pair.first;
        int time = pair.second;
        
        DFS(nextvil, N, K, distsum + time, map, dist);
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<int> dist(N + 1, 500001);
    vector<vector<pair<int, int>>> map(N + 1);
    
    for (const vector<int>& vec : road)
    {
        int a = vec[0];
        int b = vec[1];
        int time = vec[2];
        map[a].push_back({b, time});
        map[b].push_back({a, time});
    }
    
    DFS(1, N, K, 0, map, dist);
    
    for(int i : dist)
    {
        if (i <= K) answer++;
    }
    
    
    return answer;
}