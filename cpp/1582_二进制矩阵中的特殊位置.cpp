/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */
#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-09-04
 * 95/95 (16 ms)
 * Your runtime beats 82.73 % of cpp submissions
 * Your memory usage beats 40.96 % of cpp submissions (12.6 MB)
 */
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        uint16_t row = mat.size();
        uint16_t col = mat[0].size();
        int res = 0;
        uint16_t rowSum[100] = {0}, colSum[100] = {0};
        for(uint16_t r = 0; r < row; ++r) {
            for(uint16_t c = 0; c < col; ++c) {
                rowSum[r] += mat[r][c];
                colSum[c] += mat[r][c];
            }
        }

        for(uint16_t r = 0; r < row; ++r) {
            for(uint16_t c = 0; c < col; ++c) {
                if (mat[r][c] && rowSum[r] == 1 && colSum[c] == 1) {
                    ++res;
                }
            }
        }

        // cout << mat[1][2] << "\t" << rowSum[1] << '\t' << colSum[2] << endl;

        return res;
    }
};
// @lc code=end
/*
[[1,0,0],[0,0,1],[1,0,0]]\n
[[1,0,0],[0,1,0],[0,0,1]]\n
[[0,0,0,1],[1,0,0,0],[0,1,1,0],[0,0,0,0]]\n
[[0,0,0,0,0],[1,0,0,0,0],[0,1,0,0,0],[0,0,1,0,0],[0,0,0,1,1]]\n
[[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,1],[0,0,0,0,1,0,0,0],[1,0,0,0,1,0,0,0],[0,0,1,1,0,0,0,0]]
*/
