#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> cheolsu;
    map<int, int> sibling;
    for (int i : topping) cheolsu[i]++;
    for (int i : topping)
    {
        sibling[i]++;
        cheolsu[i]--;
        if(cheolsu[i] == 0) cheolsu.erase(i);
        if (cheolsu.size() == sibling.size()) answer++;
    }
    return answer;
}