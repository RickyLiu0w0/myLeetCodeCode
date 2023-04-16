/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include "AllInclude.h"

// @lc code=start
// 二维版本的前缀和
/*
    //* 放一下一维的代码
    class NumArray {
    public:
        NumArray(vector<int>& nums) : s(nums.size() + 1, 0) {
            int n = nums.size();

            for (int i = 0; i < n; ++i) {
                s[i + 1] = s[i] + nums[i];
            }
        }

        int sumRange(int left, int right) {
            return s[right + 1] - s[left];
        }

    private:
        vector<int> s;
    };
*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : pre_sum(matrix.size() + 1, vector<int>(matrix.front().size() + 1, 0)) {
        int m = matrix.size(), n = matrix.front().size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre_sum[i + 1][j + 1] = (pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j]) + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return pre_sum[row2][col2] - pre_sum[row1 - 1][col2] - pre_sum[row2][col1 - 1] + pre_sum[row1 - 1][col1 - 1];
    }

private:
    vector<vector<int>> pre_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
/*
["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[-4,-5]]],[0,0,0,0],[0,0,0,1],[0,1,0,1]]
["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
*/