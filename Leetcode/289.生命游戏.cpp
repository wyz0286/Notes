//289.生命游戏
/*3*3方向向量的另外一种表示
int neighbors[3] = {0, 1, -1};
for (int i = 0; i < 3; i++) 
{
    for (int j = 0; j < 3; j++) 
    {

        if (!(neighbors[i] == 0 && neighbors[j] == 0)) 
		{
			...
		}
    }
}*/


#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board) {    

    const int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
    const int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0; //活细胞数
            int x = i;
            int y = j;
            int a, b;
            for (int k = 0; k < 8; k++)
            {
                a = x + dx[k];
                b = y + dy[k];
                if (a >= m || a < 0 || b >= n || b < 0)continue;
                if (board[a][b] == 1 || board[a][b] == -1)++cnt;
            }
            if (board[i][j])
            {
                if (cnt < 2)board[i][j] = -1;
                else if (cnt == 2 || cnt == 3)board[i][j] = 1;
                else board[i][j] = -1;
            }
            else
            {
                if(cnt==3)board[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == -1)board[i][j] = 0;
            if (board[i][j] == 2)board[i][j] = 1;
        }
    }
}

int main()
{
    vector<vector<int>> a =
    {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    gameOfLife(a);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}