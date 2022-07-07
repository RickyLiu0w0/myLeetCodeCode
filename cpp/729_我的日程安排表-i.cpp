/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

#include "AllInclude.h"

// @lc code=start
class MyCalendar {
public:
    MyCalendar() {}

    bool book(int start, int end) {
        uint16_t size = schedule.size();
        // 二分法判断开头
        if (!size) {
            // 一个元素都没有
            schedule.emplace_back(vector<int>{start, end});
            return true;
        }

        uint16_t l = 0, r = size - 1, mid;

        if (end <= schedule[0][0]) {
            schedule.emplace(schedule.begin(), vector<int>{start, end});
            return true;
        } else if (start >= schedule[r][1]) {
            schedule.emplace_back(vector<int>{start, end});
            return true;
        }

        while (l < r) {
            mid = (r - l) / 2 + l;
            if (start > schedule[mid][0]) {
                if (l == mid) {
                    break;
                }
                l = mid;
            } else if (start < schedule[mid][0]) {
                r = mid;
            } else {
                // 开头就重合，直接退出
                return false;
            }
        }

        // l 就是最靠近start且小于start的值（索引）
        if (schedule[l][1] > start)
            return false;

        // start合法性验证通过，接下来验证end，l可以保持不动
        if ((schedule[l + 1][0] < end)) {
            return false;
        } else {
            schedule.emplace(schedule.begin() + l + 1, vector<int>{start, end});
            return true;
        }
    }

private:
    vector<vector<int>> schedule;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
/*
["MyCalendar", "book", "book"]\n
[[], [16, 18], [18,20]]\n
["MyCalendar","book","book","book"]\n
[[],[10,20],[15,25],[20,30]]\n
["MyCalendar","book","book","book","book", "book", "book"]\n
[[],[19,22],[0,20],[0,19],[17,23], [17, 19], [18, 19]]\n
["MyCalendar", "book", "book", "book"]\n
[[], [10, 20], [15, 25], [20, 30]]\n
["MyCalendar", "book", "book", "book", "book"]\n
[[], [10, 20], [5, 10], [20,25], [12, 16]]\n
["MyCalendar","book","book","book","book","book"]\n
[[],[37,50],[33,50],[4,17],[35,48],[8,25]]\n
*/