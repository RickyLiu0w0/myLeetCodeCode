/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 202-03-23
 * 102/102 (60 ms)
 * Your runtime beats 37.83 % of cpp submissions
 * Your memory usage beats 47.94 % of cpp submissions (25.1 MB)
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        size_t range_size = l.size();
        vector<bool> res;
        for (size_t i = 0; i < range_size; ++i) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());

            size_t n = r[i] + 1 - l[i];
            int sub = temp[1] - temp[0];
            bool re = true;
            for (size_t j = 1; j < n - 1; j++) {
                if (temp[j + 1] - temp[j] != sub) {
                    re = false;
                    break;
                }
            }
            res.emplace_back(re);
        }
        return res;
    }
};
// @lc code=end

