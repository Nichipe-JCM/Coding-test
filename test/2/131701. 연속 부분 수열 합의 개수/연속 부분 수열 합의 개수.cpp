#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> sums;
    for(int i = 1; i <= elements.size(); i++){
        for(int j = 0; j < elements.size(); j++){
            int sum = 0;
            for(int k = 0; k < i; k++){
                if(j + k >= elements.size()) sum += elements[j + k - elements.size()];
                else sum += elements[j + k];
            }
            sums.insert(sum);
        }
    }
    answer = sums.size();
    return answer;
}