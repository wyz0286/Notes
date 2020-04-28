//731.我的日程安排表 II

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class MyCalendarTwo {
private:
    map<int, int> help_map;
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        help_map[start]++;
        help_map[end]--;
        int temp_sum = 0;
        for (auto itr = help_map.begin(); itr != help_map.end(); ++itr) {
            temp_sum += itr->second;
            if (temp_sum == 3) {
                help_map[start]--;
                help_map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main()
{
    return 0;
}