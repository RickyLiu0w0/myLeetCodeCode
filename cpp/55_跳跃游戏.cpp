/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-25
 * 172/172 (52 ms)
 * Your runtime beats 59.36 % of cpp submissions
 * Your memory usage beats 33.33 % of cpp submissions (47.3 MB)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 贪心
        int max_len = 0, n = nums.size() - 1;
        for (int i = 0; i <= max_len; ++i) {
            max_len = max(max_len, i + nums[i]);
            if (max_len >= n) {
                return true;
            }
        }
        return max_len >= n;
    }
};
// @lc code=end

/*
[0,2,3]\n
[2,3,1,1,4]\n
[3,2,1,0,4]
*/