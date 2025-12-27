#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    char temp;
    
    for(int i = 0; i < queries.size(); i++){
        int start = queries[i][0];
        int end = queries[i][1];
        while(start<end){
            temp = my_string[start];
            my_string[start] = my_string[end];
            my_string[end] = temp;
            start++;
            end--;
        }
    }
    answer = my_string;
    return answer;
}