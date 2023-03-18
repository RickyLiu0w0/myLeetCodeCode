/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t cnt = 0;
        int res;

        for (auto& num: nums) {
            if (0 == cnt) {
                res = num;
                cnt++;
            } else if (num == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return res;
    }
};
// @lc code=end

