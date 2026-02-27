#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++)
    {
        triangle[i].assign(i + 1, 0);
    }
    
    int y = -1, x = 0;
    int num = 1;
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i % 3 == 0)
            {
                y++;
            }
            else if (i % 3 == 1)
            {
                x++;
            }
            else if (i % 3 == 2)
            {
                y--;
                x--;
            }
            triangle[y][x] = num;
            num++;
        }
    }
    for(int i = 0; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            answer.push_back(triangle[i][j]);
        }
    }
    return answer;
}