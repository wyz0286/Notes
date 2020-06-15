//面试题11.旋转数组的最小数字

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
//
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
//
//例如，数组 [3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一个旋转，该数组的最小值为1 
//
//示例 1：
//
//输入：[3, 4, 5, 1, 2]
//输出：1
//示例 2：
//
//输入：[2, 2, 2, 0, 1]
//输出：0

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minArray(vector<int>& numbers) {
    int size = numbers.size();
    if (size == 0) {
        return 0;
    }

    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        // int mid = left + ((right - left) >> 1);
        if (numbers[mid] > numbers[right]) {
            // [3, 4, 5, 1, 2]，mid 以及 mid 的左边一定不是最小数字
            // 下一轮搜索区间是 [mid + 1, right]
            left = mid + 1;
        }
        else if (numbers[mid] == numbers[right]) {
            // 只能把 right 排除掉，下一轮搜索区间是 [left, right - 1]
            right--;
        }
        else {
            // 此时 numbers[mid] < numbers[right]
            // mid 的右边一定不是最小数字，mid 有可能是，下一轮搜索区间是 [left, mid]
            right = mid;
        }
    }
    return numbers[left];
}

int main()
{
    vector<int> numbers{ 3,4,5,1,2 };
    cout << minArray(numbers) << endl;
    return 0;
}