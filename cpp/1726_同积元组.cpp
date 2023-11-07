/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-19
 * 37/37 (456 ms)
 * Your runtime beats 40.45 % of cpp submissions
 * Your memory usage beats 5.62 % of cpp submissions (99.3 MB)
 */
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long, int> mul_to_count;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mul_to_count[nums[i] * nums[j]]++;
            }
        }
        int res = 0;
        for (auto &[k, v] : mul_to_count) {
            res += (v * (v - 1)) >> 1;
        }
        return res * 8;
    }
};
// @lc code=end
