#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int three(int a, int b){
    return (10*a+b)*(10*a+b);
}

int twotwo(int a, int b){
    if (a < b) return (a+b)*(b-a);
    if (a > b) return (a+b)*(a-b);
    if (b == a) return 0;
}

int solution(int a, int b, int c, int d) {
    vector<int> ans = {a, b, c, d};
    sort(ans.begin(), ans.end());
    if(ans[0] == ans [3]){
        return ans[0]*1111;
    } else if(ans[0] == ans[2]){
        return three(ans[0], ans[3]);
    } else if(ans[1] == ans[3]){
        return three(ans[3], ans[0]);
    } else if(ans[0] == ans[1] && ans[2] == ans[3]){
        return twotwo(ans[0], ans[2]);
    } else if(ans[0] == ans[1]){
        return ans[2]*ans[3];
    } else if(ans[1] == ans[2]){
        return ans[0]*ans[3];
    } else if(ans[2] == ans[3]){
        return ans[0]*ans[1];
    }else return ans[0];
}