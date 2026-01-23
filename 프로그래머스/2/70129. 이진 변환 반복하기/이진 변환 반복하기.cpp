#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string dec = s;
    int bin;
    int zerodel = 0;
    int tobincount = 0;
    while (dec != "1"){
        string temp = "";
        for(char c : dec){
            if (c == '1'){
                temp += c;
            } else zerodel++;
        }
        bin = temp.length();
        string temp3 = "";
        while (bin > 0){
            temp3 += to_string(bin % 2);
            bin /= 2;
        }
        reverse(temp3.begin(), temp3.end());
        for(int i = 0; i < temp3.length(); i++){
            if (temp3[i] == '1'){
                dec = temp3.substr(i);
                break;
            }
        }
        tobincount++;
    }
    answer = {tobincount, zerodel};    
    return answer;
}