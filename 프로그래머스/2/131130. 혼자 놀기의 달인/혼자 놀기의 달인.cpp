#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> isopened(cards.size(), false);
    vector<int> group;
    for(int i = 0; i < cards.size(); i++)
    {
        if (isopened[i]) continue;
        isopened[i] = true;
        int count = 1;
        int currentbox = i;
        int nextbox = cards[i] - 1;
        while(!isopened[nextbox])
        {
            currentbox = nextbox;
            isopened[currentbox] = true;
            count++;
            nextbox = cards[currentbox] - 1;
        }
        group.push_back(count);
    }
    if (group.size() == 1) return 0;
    sort(group.begin(), group.end(), greater());
    answer = group[0] * group[1];
    return answer;
}