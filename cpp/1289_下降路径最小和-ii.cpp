/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-10
 * 16/16 (28 ms)
 * Your runtime beats 90.91 % of cpp submissions
 * Your memory usage beats 80.99 % of cpp submissions (14.2 MB)
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int n = grid.size();

        // grid[i][j]表示路径走到这一步的最小数字和
        for (int i = 1; i < n; ++i) {
            // 计算出上层的最小值，和次小值的下标
            int small_first_index = 0, small_first = INT_MAX;
            int samll_second_index = 0, samll_second = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int num = grid[i - 1][j];
                if (num < small_first) {
                    // 小于最小值
                    samll_second_index = small_first_index;
                    small_first_index = j;
                    samll_second = small_first;
                    small_first = num;
                } else if (num < samll_second) {
                    samll_second_index = j;
                    samll_second = num;
                }
            }
            for (int j = 0; j < n; ++j) {
                grid[i][j] += grid[i - 1][small_first_index == j ? samll_second_index : small_first_index];
            }
        }

        for (auto i : grid.back()) {
            res = min(i, res);
        }
        return res;
    }
};
// @lc code=end

