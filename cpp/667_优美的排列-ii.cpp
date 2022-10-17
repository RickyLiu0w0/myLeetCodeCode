/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */
#include "AllInclude.h"
// @lc code=start
/**
 * Accepted 2022-09-07
 * 70/70 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 18 % of cpp submissions (7.6 MB)
 */
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res = {1};
        int firstPos = 2;
        int secondPos = k+1;

        while(firstPos < secondPos) {
            res.emplace_back(secondPos);
            res.emplace_back(firstPos);

            ++firstPos;
            --secondPos;
        }

        if (firstPos == secondPos) {
            res.emplace_back(firstPos);
        }

        for (int i = k + 2; i <= n; ++i) {
            res.emplace_back(i);
        }

        return res;
    }
};
// @lc code=end

