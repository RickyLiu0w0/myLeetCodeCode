/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-02
 * 164/164 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 10.55 % of cpp submissions (10.7 MB)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto work = [&nums](int k) -> int {
            int n = nums.size(), len = 0;
            for (auto num : nums) {
                if (len < k || nums[len - k] != num) {
                    nums[len++] = num;
                }
            }
            return len;
        };
        return work(2);
    }
};
// @lc code=end

/*
[1,1,1,2,2,3]\n
[0,0,1,1,1,1,2,3,3]\n
[1,2,3,4,5]\n
[1,1,1]\n
[1,1]\n
[1]
*/