//887.鸡蛋掉落

//双蛋、K蛋问题

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        dp[1][i] = i;
    }
    for (int i = 1; i <= K; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= K; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            int left = 1, right = j;
            int mid = 1;
            while (left + 1 < right)
            {
                mid = (left + right) / 2;
                int t1 = dp[i - 1][mid - 1];
                int t2 = dp[i][j - mid];
                if (t1 > t2)right = mid;
                else if (t1 < t2) left = mid;
                else right = left = mid;
            }
            dp[i][j] = 1 + min(max(dp[i - 1][left - 1], dp[i][j - left]), max(dp[i - 1][right - 1], dp[i][j - right]));
        }
    }
    return dp[K][N];
}

int main()
{  
    cout << superEggDrop(1, 2) << endl;
    cout << superEggDrop(2, 6) << endl;
    cout << superEggDrop(3, 14) << endl;
    return 0;
}