#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int row = board.size();
    int column = board[0].size();
    int currentanswer = -1;
    while(currentanswer != answer)
    {
        currentanswer = answer;
        vector<vector<bool>> issquared(row, vector<bool>(column));
        
        for(int i = 0; i < row - 1; i++)
        {
            for(int j = 0; j < column - 1; j++)
            {
                if (board[i][j] == 'X') continue;
                if (board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j + 1])
                {
                    issquared[i][j] = true;
                    issquared[i + 1][j] = true;
                    issquared[i][j + 1] = true;
                    issquared[i + 1][j + 1] = true;
                }
            }
        }
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if (issquared[i][j])
                {
                    answer++;
                    board[i][j] = 'X';
                }
            }
        }
        
        for(int j = 0; j < column; j++)
        {
            int bottom = -1;
            for(int i = row - 1; i >= 0; i--)
            {
                if(board[i][j] == 'X' && i > bottom) bottom = i;
                if(board[i][j] != 'X' && i < bottom)
                {
                    board[bottom][j] = board[i][j];
                    board[i][j] = 'X';
                    bottom--;
                }
            }
        }
        
    }
    return answer;
}