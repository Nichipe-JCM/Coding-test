#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct namephrase{
    string head;
    string number;
};

namephrase tostruct(const string& s){
    namephrase newstruct;
    int phase = 0;
    string head = "", number = "";
    for(int i = 0; i < s.length(); i++)
    {
        if (phase == 0)
        {
            if (isdigit(s[i]))
            {
                phase++;
                number += s[i];
            }
            else head += tolower(s[i]);
        }
        else if (phase == 1)
        {
            if (!isdigit(s[i]) || number.size() == 5) break;
            else number += s[i];
        }
    }
    newstruct.head = head;
    newstruct.number = number;
    return newstruct;
}

vector<string> solution(vector<string> files) {
    vector<string> answer(files.size());
    answer = files;
    
    stable_sort(answer.begin(), answer.end(), [](string a, string b){
        namephrase Aphrase = tostruct(a);
        namephrase Bphrase = tostruct(b);
        string Ahead = Aphrase.head;
        string Bhead = Bphrase.head;
        int Anum = stoi(Aphrase.number);
        int Bnum = stoi(Bphrase.number);
        
        if (Ahead != Bhead) return Ahead < Bhead;
        if (Anum != Bnum) return Anum < Bnum;
        return false;
    });
    
    return answer;
}