/*
 * @lc app=leetcode.cn id=2731 lang=cpp
 *
 * [2731] 移动机器人
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-10
 * 2572/2572 (112 ms)
 * Your runtime beats 65.43 % of cpp submissions
 * Your memory usage beats 20.75 % of cpp submissions (94.8 MB)
*/
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        // 关键在于可以无视机器人碰撞
        int n = s.length();
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            // 在(s[i] & 2 ) - 1)的算式下，L = -1，R = 1
            v[i] = (long long)nums[i] + d * ((s[i] & 2 ) - 1);
        }
        sort(v.begin(), v.end());
        long long res = 0, sum = 0;
        /*
         * 在计算v[i]和前面距离的之后，有
         * res = (v[i] - v[0]) + (v[i] - v[1]) + ... + v[i] - v[i - 1]
         *     = i * v[i] - (v[0] + v[1] + v[2] + ... + v[i - 1])
        */
        const int MOD = (1e9 + 7);
        for (int i = 0; i < n; ++i) {
            res = (res + v[i] * i - sum) % MOD;
            sum += v[i];
        }
        return res;
    }
};
// @lc code=end
