#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> vec;
    int first = 0;
    int second = 1;
    int size = numbers.size();
    while(true){
        if(first + 1 == size) break;
        vec.push_back(numbers[first] + numbers[second]);
        second++;
        if(second == size){
            first++;
            second = first + 1;
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size()-1; i++){
        if(vec[i] == vec[i+1]){
            vec.erase(vec.begin() + i + 1);
            i--;
        }
    }
    answer = vec;
    return answer;
}