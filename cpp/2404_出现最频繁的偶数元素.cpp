/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-13\
 * 219/219 cases passed (52 ms)
 * Your runtime beats 88.85 % of cpp submissions
 * Your memory usage beats 98.14 % of cpp submissions (29.7 MB)
 */
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 1, n = nums.size();  // [left, right)
        int res = -1;
        int res_num = -1;
        while (left < n) {
            int num = nums[left];
            while (right < n && num == nums[right]) {
                ++right;
            }

            if (num % 2 == 0) {
                if (res < right - left) {
                    res = right - left;
                    res_num = num;
                }
            }
            left = right;
            ++right;
        }
        return res_num;
    }
};
// @lc code=end
