/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-22
 * 564/564 (88 ms)
 * Your runtime beats 93.97 % of cpp submissions
 * Your memory usage beats 66.9 % of cpp submissions (81.8 MB)
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for (auto & num : nums) {
            num = (num << 1) - 1; // 1 -> 1, 0 -> -1
        }
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 0;
        int res = 0;
        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            if (hash.count(sum)) {
                // 找到s[i]，令s[j] - s[i] == 0
                res = max(res, j + 1 - hash[sum]);
            } else {
                hash[sum] = j + 1;
            }
        }
        return res;
    }
};
// @lc code=end
/*
[0,1]\n
[0,1,0]\n
[1,1,1]\n
[0,1,1,0]\n
[0,1,1,0,1,1,1,0]
*/
