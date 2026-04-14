#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1);
    vector<bool> isvisited(n + 1);
    for(vector<int> v : edge)
    {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    queue<int> q;
    q.push(1);
    distance[1] = 0;
    isvisited[1] = true;
    
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for(int i : graph[current])
        {
            if (!isvisited[i])
            {
                isvisited[i] = true;
                distance[i] = distance[current] + 1;
                q.push(i);
            }
        }
    }
    
    int maxdistance = *max_element(distance.begin(), distance.end());
    answer = count(distance.begin(), distance.end(), maxdistance);
    return answer;
}