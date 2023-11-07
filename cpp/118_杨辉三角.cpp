/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-01
 * 30/30 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 5.12 % of cpp submissions (7.2 MB)
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        int cnt = 1;
        while (cnt < numRows) {
            vector<int> lev(++cnt, 1);
            for (int i = 1; i < cnt - 1; ++i) {
                lev[i] = res.back()[i - 1] + res.back()[i];
            }
            res.emplace_back(move(lev));
        }
        return res;
    }
};
// @lc code=end

/*
1\n
2\n
3\n
5\n
30
*/