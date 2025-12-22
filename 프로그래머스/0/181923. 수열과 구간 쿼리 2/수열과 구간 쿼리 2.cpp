#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        vector<int> temp;
        vector<int> temp2;
        for (int j = 0; j < queries[i][1]+1; j++) {
            if(j >= queries[i][0] && j <= queries[i][1]){
                temp.push_back(arr[j]);
            }
        }
        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] > queries[i][2]) {
                temp2.push_back(temp[k]);
            }
        }
        if (temp2.size() == 0) {
            answer.push_back(-1);
        }
        else if (temp2.size() == 1) {
            answer.push_back(temp2[0]);
        }
        else if (temp2.size() >= 2) {
            sort(temp2.begin(), temp2.end());
            answer.push_back(temp2[0]);
        }
    }
    return answer;
}