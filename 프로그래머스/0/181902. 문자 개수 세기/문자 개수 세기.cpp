#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    vector<char> alpha = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i < my_string.length(); i++){
        for(int j = 0; j < alpha.size(); j++){
            if (my_string[i] == alpha[j]) answer[j]++;
        }
    }
    return answer;
}