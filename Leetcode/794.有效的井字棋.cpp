//794.有效的井字游戏
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool win(vector<string>& board, const char& c)
{
    for (int i = 0; i < 3; i++)
    {
        if (c == board[0][i] && c == board[1][i] && c == board[2][i])return true;
        if (c == board[i][0] && c == board[i][1] && c == board[i][2])return true;
    }
    if (c == board[0][0] && c == board[1][1] && c == board[2][2])return true;
    if (c == board[2][0] && c == board[1][1] && c == board[0][2])return true;
    return false;
}

bool validTicTacToe(vector<string>& board) {
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')count++;
            if (board[i][j] == 'O')count--;
        }
    }
    if (count < 0 || count>1)return false;
    bool winx = win(board, 'X');
    bool wino = win(board, 'O');
    if (winx && !wino)return count == 1;
    else if (!winx && wino)return count == 0;
    else if (winx && wino)return false;
    return true;
}

int main()
{
    return 0;
}