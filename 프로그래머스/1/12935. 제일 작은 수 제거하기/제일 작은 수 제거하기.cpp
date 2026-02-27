#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1){
        arr.clear();
        arr.push_back(-1);
        return arr;
    }
    int comp = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(comp > arr[i]){
            comp = arr[i];
        }
    }
    auto it = find(arr.begin(), arr.end(), comp);
    arr.erase(it);
    answer = arr;
    return answer;
}