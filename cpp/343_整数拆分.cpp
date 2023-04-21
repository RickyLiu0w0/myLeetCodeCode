/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-19
 * 50/50 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 62.67 % of cpp submissions (6 MB)
 */
class Solution {
public:
    /*
    int integerBreak(int n) {
        vector<int> dp(59);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int num = 0;
            int mid = i >> 1;
            for (int j = 1; j <= mid; ++j) {
                num = std::max(num, std::max(dp[j] * dp[i - j], std::max(j * dp[i - j], std::max(dp[j] * (i - j), j * (i
    - j)))));
            }
            dp[i] = num;
            // cout << "i: " << i << " num: " << num << endl;
        }
        return dp[n];
    }*/

    /*
    int integerBreak(int n) {
        if (n < 3)
            return 1;  // 1, 1
        if (n == 3)
            return 2;  // 1,2

        // 可以证明，按照3，3，3这样切割可以乘积最大
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }

        /**
         * 最后剩下4，就分为 2 * 2
         * 最后剩下3，就直接乘上3，不拆分
         * 最后剩下2，就乘上2，也不拆分
         * 最后剩下1，就乘上1，也不拆分
        return n * res;
    }
    */
    int integerBreak(int n) {
        vector<int> memo(59, -1);
        memo[0] = 0;
        memo[1] = 1;
        function<int(int)> dp = [&](int nn) -> int {
            if (memo[nn] != -1) {
                return memo[nn];
            }

            int res = INT_MIN;
            for (int i = 1; i < nn; i++) {
                res = max(res, i * max(nn - i, dp(nn - i)));
            }
            memo[nn] = res;
            return res;
        };
        return dp(n);
    }
};
// @lc code=end
