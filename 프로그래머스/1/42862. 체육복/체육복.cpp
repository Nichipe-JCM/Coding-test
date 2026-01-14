#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> vec (n+2 , 1);
    
    for(int l : lost){
        vec[l]--;
    }
    for(int r : reserve){
        vec[r]++;
    }
    
    for(int i = 1; i <= n; i++){
        if (vec[i] == 0){
            if(vec[i-1] == 2){
                vec[i-1]--;
                vec[i]++;
            }
            else if(vec[i+1] == 2){
                vec[i+1]--;
                vec[i]++;
            }
        }
    }
    
    answer = n - count(vec.begin(), vec.end(), 0);
    return answer;
}