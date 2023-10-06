/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-19
 * 21/21 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 6.41 % of cpp submissions (7.1 MB)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先按左上右下对角线反转
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end

