/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-03
 * 190/190 (4 ms)
 * Your runtime beats 95.28 % of cpp submissions
 * Your memory usage beats 10.78 % of cpp submissions (14.3 MB)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res, n = nums.size();
        vector<int> min_array(n);
        vector<int> max_array(n);
        res = min_array[0] = max_array[0] = nums.front();

        for (int i = 1; i < n; ++i) {
            min_array[i] = min(min(min_array[i - 1] * nums[i], max_array[i - 1] * nums[i]), nums[i]);
            max_array[i] = max(max(min_array[i - 1] * nums[i], max_array[i - 1] * nums[i]), nums[i]);
            res = max(res, max_array[i]);
        }

        return res;
    }
};
// @lc code=end

