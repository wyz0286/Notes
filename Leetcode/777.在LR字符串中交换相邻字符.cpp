//777.在LR字符串中交换相邻字符

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool canTransform(string start, string end) {
    int n = start.length();
    int i = -1, j = -1;
    while (++i < n && ++j < n) {
        while (i < n && start[i] == 'X') i++;
        while (j < n && end[j] == 'X') j++;
        /* At this point, i == n or start[i] != 'X',
           and j == n or end[j] != 'X'.  i and j
           are the indices representing the next
           occurrences of non-X characters in start and end.
        */

        // If only one of i < n and j < n, then it isn't solid-
        // there's more people in one of the strings.
        if ((i < n) ^ (j < n)) return false;

        if (i < n && j < n) {
            // If the person isn't the same, it isn't solid.
            // Or, if the person moved backwards, it isn't accessible.
            if (start[i] != end[j] || (start[i] == 'L' && i < j) ||
                (start[i] == 'R' && i > j))
                return false;
        }
    }
    return true;
}

//bool canTransform(string start, string end) {
//    string s1 = start, s2 = end;
//    s1.erase(std::remove(s1.begin(), s1.end(), 'X'), s1.end());
//    s2.erase(std::remove(s2.begin(), s2.end(), 'X'), s2.end());
//    if (s1 != s2)return false;
//
//    int t = 0;
//    for (int i = 0; i < start.length(); ++i)
//        if (start[i] == 'L') {
//            while (end[t] != 'L') t++;
//            if (i < t++) return false;
//        }
//
//    t = 0;
//    for (int i = 0; i < start.length(); ++i)
//        if (start[i] == 'R') {
//            while (end[t] != 'R') t++;
//            if (i > t++) return false;
//        }
//    return true;
//}

int main()
{  
    cout << canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
    return 0;
}