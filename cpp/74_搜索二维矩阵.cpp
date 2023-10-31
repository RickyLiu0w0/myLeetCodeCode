/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-11
 * 133/133 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 5.04 % of cpp submissions (9.8 MB)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        int i = m - 1;
        while (i > -1) {
            if (matrix[i][0] > target) {
                --i;
            } else {
                break;
            }
        }
        if (i == -1) {
            return false;
        }
        int j = 0;
        while (j < n) {
            if (matrix[i][j] < target) {
                ++j;
            } else{
                return matrix[i][j] == target;
            }
        }
        return false;
    }
};
// @lc code=end

