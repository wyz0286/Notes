//877.石子游戏
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool stoneGame(vector<int>& piles) {
    int n = piles.size();

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int size = 1; size <= n; ++size)
        for (int i = 1, j = size; j <= n; ++i, ++j) 
        {
            int parity = (j + i + n) % 2;  // j - i - N; but +x = -x (mod 2)
            if (parity == 1)
                dp[i][j] = max(piles[i - 1] + dp[i + 1][j], piles[j - 1] + dp[i][j - 1]);
            else
                dp[i][j] = min(-piles[i - 1] + dp[i + 1][j], -piles[j - 1] + dp[i][j - 1]);
        }

    return dp[1][n] > 0;

}

int main()
{
    vector<int> a = { 5,3,4,5 };
    cout << stoneGame(a) << endl;
}