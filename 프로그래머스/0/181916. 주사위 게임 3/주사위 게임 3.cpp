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
    if(a == b && b == c && c == d) return a*1111;
    if(a == b && a == c && a != d) return three(a,d);
    if(a == b && a != c && a == d) return three(a,c);
    if(a != b && a == c && a == d) return three(a,b);
    if(a != b && b == c && b == d) return three(b,a);
    if(a == b && b != c && c == d) return twotwo(a,d);
    if(a == c && b != c && b == d) return twotwo(a,d);
    if(a == d && a != b && b == c) return twotwo(a,b);
    if(a == b && b != c && b != d && c != d) return c*d;
    if(a == c && c != b && c != d && b != d) return b*d;
    if(a == d && d != b && d != c && b != c) return b*c;
    if(b == c && c != a && c != d && a != d) return a*d;
    if(b == d && d != a && d != c && a != c) return a*c;
    if(c == d && d != a && d != b && a != b) return a*b;
    vector<int> ans = {a, b, c, d};
    sort(ans.begin(), ans.end());
    return ans[0];
}