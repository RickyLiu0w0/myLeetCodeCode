/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-31
 * 104/104 (4 ms)
 * Your runtime beats 78.69 % of cpp submissions
 * Your memory usage beats 45.36 % of cpp submissions (8.4 MB)
*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; ++i) {
            auto pos = find(nums.begin() + i, nums.end(), nums[i] + diff);
            
            if (pos == nums.end()) {
                continue;
            }

            if (find(pos, nums.end(), nums[i] + 2 * diff) == nums.end()) {
                continue;
            }

            res++;
        }
        return res;
    }
};
// @lc code=end

