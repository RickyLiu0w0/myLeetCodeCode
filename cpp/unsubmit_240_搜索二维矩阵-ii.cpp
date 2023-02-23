/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从右上角开始，向左是减少，向下是增大
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;

        while (-1 != col && m != row ) {
            if (matrix[row][col] > target) {
                // 往左
                --col;
            } else if (matrix[row][col] < target) {
                // 往下
                ++row;
            } else {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
