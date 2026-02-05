#include <string>
#include <vector>

using namespace std;

void dfs(string current, int& count, int& answer, const string& word, string& vowels)
{
    if (answer > 0) return;
    if (current.length() == 5) return;
    
    for(int i = 0; i < 5; i++){
        string next = current + vowels[i];
        count++;
        if (next == word)
        {
            answer = count;
            break;
        }
        dfs(next, count, answer, word, vowels);
    }
}

int solution(string word) {
    int answer = 0;
    int count = 0;
    string vowels = "AEIOU";
    dfs("", count, answer, word, vowels);
    return answer;
}