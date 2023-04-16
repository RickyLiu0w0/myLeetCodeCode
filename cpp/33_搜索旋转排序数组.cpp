/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-15
 * 195/195  (4 ms)
 * Your runtime beats 68.79 % of cpp submissions
 * Your memory usage beats 46.04 % of cpp submissions (10.8 MB)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto is_blue = [&nums, target](int mid) -> bool {
            if (nums.back() < nums[mid]) {
                return target > nums.back() && target <= nums[mid];
            } else {
                return target > nums.back() || target <= nums[mid];
            }
        };

        // (l, r) 开区间
        int l = -1, r = nums.size() - 1;

        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            if (is_blue(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return nums[r] != target ? -1 : r;
    }
};
// @lc code=end

