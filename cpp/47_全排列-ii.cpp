/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-12
 * 33/33 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 86.14 % of cpp submissions (8.3 MB)
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> path;
        int n = nums.size();

        function<void(int, uint8_t)> backtrace = [&](int i, uint8_t code) {
            if (i == n) {
                v.emplace_back(path);

                return;
            }
            int pre_sum = -11;
            for (int j = 0; j < n; ++j) {
                // 不要和前一个一样，和前一个一样的话，它的递归结果已经算过
                if (pre_sum != nums[j] && !(code & (1 << j))) {
                    pre_sum = nums[j];
                    path.emplace_back(nums[j]);
                    backtrace(i + 1, code | (1 << j));
                    path.pop_back();
                }
            }
        };
        sort(nums.begin(), nums.end());
        backtrace(0, 0);
        return v;
    }
};
// @lc code=end

