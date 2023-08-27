/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-26
 * 31/31 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 7.52 % of cpp submissions (6.8 MB)
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return {};
        }
        long target = nums[0] + 1, base = nums[0];
        vector<string> res;
        for (int i = 1; ; ++i) {
            if (i != n && nums[i] == target) {
                ++target;
            } else {
                if (base == target - 1) {
                    res.emplace_back(to_string(base));
                } else {
                    res.emplace_back(to_string(base) + "->" + to_string(target - 1));
                }
                if (i == n) {
                    break;
                }
                base = nums[i];
                target = base + 1;
            }
        }
        return res;
    }
};
// @lc code=end
/*
[0,1,2,4,5,7]\n
[0,2,3,4,6,8,9]\n
[]\n
[1,2,3,4,5,6,8,9,10,15,19,20,21,22,23,24,25,26,27]\n
[-1]\n
[-2147483648,-2147483647,2147483647]
*/
