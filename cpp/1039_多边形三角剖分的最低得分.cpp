/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-02
 * 94/94 (12 ms)
 * Your runtime beats 20.13 % of cpp submissions
 * Your memory usage beats 23.94 % of cpp submissions (8.3 MB)
 */
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // 计算从i到j的字问题
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j == i + 1) {
                // 没有三角形
                return 0;
            }
            if (dp[i][j] != -1) return dp[i][j];

            int res = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                // 枚举(i,k)多边形，(k,j)多边形，以及[i,j,k]三角形
                res = min(res, values[i] * values[j] * values[k] + dfs(i, k) + dfs(k, j));
            }
            dp[i][j] = res;
            return res;
        };

        return dfs(0, n - 1);
    }
};
// @lc code=end
