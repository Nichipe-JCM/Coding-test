#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    map<char, int> namemap;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        namemap[s[0]]++;
    }
    string over5list = "";
    for(const auto& pair : namemap) if (pair.second >= 5) over5list += pair.first;
    if (over5list == "") cout << "PREDAJA";
    else cout << over5list;
}