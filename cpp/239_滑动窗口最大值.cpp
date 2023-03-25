/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-20
 * 51/51 cases passed (236 ms)
 * Your runtime beats 44.71 % of cpp submissions
 * Your memory usage beats 58.23 % of cpp submissions (131.5 MB)
*/
class MyQueue {
public:
    void push_back(int n) {
        while (!q.empty() && q.back() < n) {
            q.pop_back();
        }
        q.emplace_back(n);
    }

    int max() { return q.front(); }

    void pop(int n) {
        if (n == q.front()) {
            q.pop_front();
        }
    }

private:
    deque<int> q;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue my_q;
        vector<int> res;
        size_t i = 0, n = nums.size();
        while (i < k) {
            my_q.push_back(nums.at(i));
            ++i;
        }
        res.emplace_back(my_q.max());

        while (i < n) {
            my_q.push_back(nums.at(i));
            my_q.pop(nums.at(i - k));
            res.emplace_back(my_q.max());
            ++i;
        }
        return res;
    }
};
// @lc code=end
