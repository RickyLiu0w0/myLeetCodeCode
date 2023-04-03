/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-03
 * 74/74 (16 ms)
 * Your runtime beats 63.6 % of cpp submissions
 * Your memory usage beats 8.88 % of cpp submissions (12.7 MB)
*/
class Solution {
    // 题目就是最长公共子序列
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /**
         * dp[i][j]代表num1的[0, i]以及num2[0, j]的最长公共子序列
         *               _
         *              | dp[i-1][j-1] + 1  (nums1[i] == nums2[j])
         * dp[i][j] == <
         *              | max(dp[i-1][j], dp[i][j-1])) (nums1[i] != nums2[j])
         *               _
         */

        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // for (auto& v : dp) {
        //     for (auto& num : v) {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];
    }
};
// @lc code=end

/*
[1,1,2,1,2]\n[1,3,2,3,1]\n
[1,4,2]\n[1,2,4]\n
[2,5,1,2,5]\n[10,5,2,1,5,2]\n
[1,3,7,1,7,5]\n[1,9,2,5,1]\n
*/