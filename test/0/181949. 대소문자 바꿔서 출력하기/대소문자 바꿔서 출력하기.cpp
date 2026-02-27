#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    char upper[] {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lower[] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cin >> str;
    for(int i = 0; i < str.size();i++){
        char temp = ' ';
        temp = str[i];        
        for(int j = 0; j < 27; j++){
            if(temp == upper[j]){
                temp = lower[j];
                str[i] = temp;
                break;
            } else if(temp == lower[j]){
                temp = upper[j];
                str[i] = temp;
                break;
            }
        }
    }
    cout << str;
    return 0;
}