/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-14
 * 84/84 (56 ms)
 * Your runtime beats 77 % of cpp submissions
 * Your memory usage beats 87 % of cpp submissions (32.5 MB)
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> res(rowSum.size(), vector<int>(colSum.size(), 0));

        while (1) {
            auto row_min_index = min_element(rowSum.begin(), rowSum.end());
            auto col_min_index = min_element(colSum.begin(), colSum.end());
            auto iter = *row_min_index < *col_min_index ? row_min_index : col_min_index;

            if (*iter == INT_MAX) {
                return res;
            }

            res[row_min_index - rowSum.begin()][col_min_index - colSum.begin()] = *iter;
            int num = *iter;
            *row_min_index = *row_min_index == num ? INT_MAX : *row_min_index - num;
            *col_min_index = *col_min_index == num ? INT_MAX : *col_min_index - num;
        }

        return res;
    }
};
// @lc code=end
