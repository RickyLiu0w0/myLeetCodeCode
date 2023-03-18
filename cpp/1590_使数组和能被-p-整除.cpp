/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-10
 * 142/142 (184 ms)
 * Your runtime beats 28.66 % of cpp submissions
 * Your memory usage beats 56.05 % of cpp submissions (65 MB)
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        /**
         * range_sum = pre_sum[j] - pre_sum[i]; i < j
         * (all_sum - range_sum) % p == 0
         * 
         * (all_sum - (pre_sum[j] - re_sum[i]) %  p) == 0
         * all_sum % p ==  (pre_sum[j] - pre_sum[i]) % p
         * 
         * pre_sum[i] % p == (pre_sum[j] - all_sum) % p
         * pre_sum[i] % p == pre_sum[j] % p - all_sum % p
         * target == pre_mod - all_mod
         * 
        */

        long long all_sum = 0LL;
        for (auto& num : nums) {
            all_sum += num;
        }
        if (all_sum < p) return -1;

        int all_mod = all_sum % p;
        long long pre_sum = 0LL;
        const size_t size = nums.size();
        int res = size;

        if (all_mod == 0) return 0;

        unordered_map<int, int> map;
        map[0] = -1;

        for (int i = 0; i < size; ++i) {
            pre_sum += nums[i];
            int pre_mod = pre_sum % p;
            int target = (pre_mod - all_mod + p) % p;

            if (map.count(target)) {
                // 存在target == pre_mod - all_mod
                res = std::min(res, i - map[target]);
            }
            map[pre_mod] = i;
        }

        return res == size ? -1 : res;
    }
};
// @lc code=end

