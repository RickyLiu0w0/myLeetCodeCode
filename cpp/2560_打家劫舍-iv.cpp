/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-19
 * 64/64 (124 ms)
 * Your runtime beats 84.7 % of cpp submissions
 * Your memory usage beats 47.23 % of cpp submissions (56 MB)
*/
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // 偷窃能力越小，k越小；反之亦然，所以有线性关系
        // 二分偷窃能力，看满足该偷窃能力之下能否满足k的条件
        auto is_blue = [&nums, k](int ability) -> bool {
            int n = nums.size(), cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= ability) {
                    // 可偷
                    i++;
                    cnt++;
                }
            }
            return cnt >= k;
        };
        
        int left = 0, right = * max_element(nums.begin(), nums.end());
        while (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            (!is_blue(mid) ? left : right) = mid;
        }
        return right;
    }
};
// @lc code=end

