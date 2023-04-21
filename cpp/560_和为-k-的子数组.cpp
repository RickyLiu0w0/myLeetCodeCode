/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-21
 * 93/93 (68 ms)
 * Your runtime beats 86.69 % of cpp submissions
 * Your memory usage beats 43.49 % of cpp submissions (40.6 MB)
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, res = 0, sum = 0;
        unordered_map<int, int> pre_sum_map;
        pre_sum_map[0] = 1;
        int i = 0;

        // s[j] - s[i] = k
        // s[j] - k = s[i] 要确保 i < j
        for (auto& num : nums) {
            sum += num;
            if (pre_sum_map.count(sum - k)) {
                // 找到s[i]
                res += pre_sum_map[sum - k];
            }
            pre_sum_map[sum]++;
        }
        return res;
    }
};
// @lc code=end
/*
[1,1,1]\n2\n
[1,2,3]\n3\n
[1,2,3,2,1,3]\n3\n
[1]\n0\n
[1,4,-4]\n4\n
[-1,0,1]\n0\n
[0,0,0]\n0
*/
