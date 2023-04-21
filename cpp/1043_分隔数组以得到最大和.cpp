/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-20
 * 52/52 (20 ms)
 * Your runtime beats 31.6 % of cpp submissions
 * Your memory usage beats 14.55 % of cpp submissions (8.4 MB)
 */
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // 返回[0,i]的最大值，包含i
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int max_ = 0, res = 0;
            for (int j = i; i - j < k && j >= 0; --j) {
                max_ = max(max_, arr[j]);
                res = max(res, dp[j] + max_ * (i - j + 1));
            }
            dp[i + 1] = res;
        }

        /*
        function<int(int)> dp = [&](int i) -> int {
            if (memo[i+1] != -1) {
                return memo[i + 1];
            }

            // [(0, 1, ...， i - k), (i - k + 1, ..., i - 1, i)]
            // j就从i开始往前到i-k+1的位置
            int max_ = 0, res = 0;
            for (int j = i; i - j < k && j >= 0; --j) {
                max_ = max(max_, arr[j]);
                res = max(res, dp(j - 1) + max_ * (i - j + 1));
            }
            memo[i+1] = res;
            return res;
        };*/
        return dp[n];
    }
};
// @lc code=end
/*
[20779,436849,274670,543359,569973,280711,252931,424084,361618,430777,136519,749292,933277,477067,502755,695743,413274,168693,368216,677201,198089,927218,633399,427645,317246,403380,908594,854847,157024,719715,336407,933488,599856,948361,765131,335089,522119,403981,866323,519161,109154,349141,764950,558613,692211]\n
26
*/