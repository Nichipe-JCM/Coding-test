#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_length = 0;
    int current_weight = 0;
    int index = 0;
    queue<pair<int,int>> on_bridge;
    
    while(true)
    {
        answer++;
        if (!on_bridge.empty())
        {
            if(answer - on_bridge.front().second >= bridge_length)
            {
                current_length -= 1;
                current_weight -= truck_weights[on_bridge.front().first];
                on_bridge.pop();
            }
        }
        
        if(index < truck_weights.size() && current_weight + truck_weights[index] <= weight && current_length + 1 <= bridge_length)
        {
            on_bridge.push({index, answer});
            current_length += 1;
            current_weight += truck_weights[index];
            index++;
        }

        if (index == truck_weights.size() && on_bridge.empty()) break;
    }
    
    return answer;
}