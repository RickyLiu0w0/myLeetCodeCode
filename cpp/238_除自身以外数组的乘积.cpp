/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-08
 * 22/22 (32 ms)
 * Your runtime beats 11.43 % of cpp submissions
 * Your memory usage beats 79.45 % of cpp submissions (23.4 MB)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i > -1; --i) {
            res[i] *= nums[i + 1];
            nums[i] *= nums[i + 1];
        }
        return res;
    }
};
// @lc code=end

/*
[1,2,3,4]\n
[-1,1,0,-3,3]\n
[-30, 30]
*/