/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-07-19 10:36
 * 97/97 (236 ms)
 * Your runtime beats 26.35 % of cpp submissions
 * Your memory usage beats 73.04 % of cpp submissions (37.8 MB)
 */
class MyCalendarTwo {
public:
    MyCalendarTwo() { this->M_.clear(); }

    bool book(int start, int end) {
        int maxBook = 0;
        // 对区间内的数集体+1
        ++this->M_[start];
        --this->M_[end];

        for (pair<const int, int> &t : this->M_) {
            maxBook += t.second;
            if (maxBook > 2) {
                --this->M_[start];
                ++this->M_[end];
                return false;
            }
        }

        return true;
    }

    map<int, int> M_;  // <区间端点，统计次数>
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
