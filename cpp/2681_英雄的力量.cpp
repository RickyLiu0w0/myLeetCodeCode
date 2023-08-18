/*
 * @lc app=leetcode.cn id=2681 lang=cpp
 *
 * [2681] 英雄的力量
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-01
 * 2584/2584 (80 ms)
 */
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int res = 0, s = 0;
        for (long long x: nums) { // x 作为最大值
            res = (res + x * x % MOD * (x + s)) % MOD; // 中间模一次防止溢出
            s = (s * 2 + x) % MOD; // 递推计算下一个 s
        }
        return res;
    }
};
// @lc code=end

