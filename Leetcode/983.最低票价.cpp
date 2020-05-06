//983.最低票价

#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
private:
    vector<int> days, costs;
    vector<int> memo;
    int durations[3] = { 1, 7, 30 };

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        memo.assign(days.size(), -1);
        return dp(0);
    }

    int dp(int i) {
        if (i >= days.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; ++k) {
            while (j < days.size() && days[j] < days[i] + durations[k]) {
                ++j;
            }
            memo[i] = min(memo[i], dp(j) + costs[k]);
        }
        return memo[i];
    }
};

int main()
{
	cout << endl;
    return 0;
}