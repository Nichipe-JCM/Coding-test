#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int target = 1;
    auto it = ingredient.begin();
    while(true){
        it = find(it, ingredient.end(), 1);
        if (ingredient.end() - it <=3) break;
        if (it != ingredient.end()){
            if (*it == 1 &&
               *(it+1) == 2 &&
               *(it+2) == 3 &&
               *(it+3) == 1){
                answer++;
                it = ingredient.erase(it, it+4);
                if(it - 3 < ingredient.begin()) it = ingredient.begin();
                else it -= 3;
            }
            else it += 1;
        }
        
    }
    return answer;
}