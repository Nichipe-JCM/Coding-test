#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int a = 0, b = num_list.size() - 1, c = 1;
    switch(n)
    {
        case 1:
            b = slicer[1];
            break;
        case 2:
            a = slicer[0];
            break;
        case 3:
            a = slicer[0];
            b = slicer[1];
            break;
        case 4:
            a = slicer[0];
            b = slicer[1];
            c = slicer[2];
            break;
    }
    for(int i = a; i <= b; i += c)
    {
        answer.push_back(num_list[i]);
    }
    return answer;
}