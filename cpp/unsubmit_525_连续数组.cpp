/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

#include "AllInclude.h"

// @lc code=start
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
