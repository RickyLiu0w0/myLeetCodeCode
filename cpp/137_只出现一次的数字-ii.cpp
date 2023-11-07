/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-15
 * 14/14 (8 ms)
 * Your runtime beats 70.47 % of cpp submissions
 * Your memory usage beats 32.57 % of cpp submissions (9.6 MB)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 将二进制1的个数统计下来，mod 3，剩下的就是答案
        vector<int> v(32, 0);
        for (auto& num : nums) {
            for (int i = 0; i < 32; ++i) {
                v[i] += (num >> i) & 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res |= (v[i] % 3) << i;
        }
        return res;
    }
};
// @lc code=end

/*
[30000,500,100,30000,100,30000,100]\n
[2,2,3,2]\n
[0,1,0,1,0,1,99]\n
[1,1,1,3]
*/