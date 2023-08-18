/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-07
 * 34/34 (44 ms)
 * Your runtime beats 70.93 % of cpp submissions
 * Your memory usage beats 63.54 % of cpp submissions (32.9 MB)
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // nums[i] == i + 1，将数字归位到正确的下标上，如果位置上已经有正确的值，则直接跳过
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                int t = nums[i];
                if (t == nums[t - 1]) {
                    continue;
                }
                nums[i] = nums[t - 1];
                nums[t - 1] = t;
                --i;
                // for (int j = 0; j < n; ++j) {
                //     cout << nums[j] << ' ';
                // }
                // cout << endl;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end

