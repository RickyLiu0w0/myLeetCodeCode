/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-10
 * 56/56 (212 ms)
 * Your runtime beats 38.88 % of cpp submissions
 * Your memory usage beats 23.6 % of cpp submissions (97.8 MB)
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        int n = potions.size();
        for (long long spell : spells) {
            int j = lower_bound(potions.begin(), potions.end(), success / (double)spell) - potions.begin();
            int len = n - j;
            res.emplace_back(len);
        }
        return res;
    }
};
// @lc code=end

